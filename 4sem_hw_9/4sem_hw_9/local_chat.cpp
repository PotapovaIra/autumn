#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

class Chat
{
private:
    using shared_memory_t = boost::interprocess::managed_shared_memory;
    using manager_t = boost::interprocess::managed_shared_memory::segment_manager;
    using string_allocator_t = boost::interprocess::allocator<char, manager_t>;
    using string_t = boost::interprocess::basic_string<char, std::char_traits<char>, string_allocator_t>;
    using vector_allocator_t = boost::interprocess::allocator<string_t, manager_t>;
    using vector_t = boost::interprocess::vector<string_t, vector_allocator_t>;
    using mutex_t = boost::interprocess::interprocess_mutex;
    using condition_t = boost::interprocess::interprocess_condition;
    using counter_t = std::atomic<std::size_t>;

public:
    explicit Chat(const std::string& user_name) : m_user_name(user_name), m_exit_flag(false),
        m_shared_memory(boost::interprocess::open_or_create, shared_memory_name.c_str(), 65536) //replaced create_only by open or create
    {
        m_vector = m_shared_memory.find_or_construct<vector_t>("Messages")(m_shared_memory.get_segment_manager());
        m_mutex = m_shared_memory.find_or_construct<mutex_t>("Mutex")(); //find_or_construct instead of construct
        m_condition = m_shared_memory.find_or_construct<condition_t>("Condition")();
        m_users = m_shared_memory.find_or_construct<counter_t>("Users")(0); //0 instead of 1, then increment
        m_messages = m_shared_memory.find_or_construct<counter_t>("Messages")(0);
        if (++(*m_users) == 1) 
        {
            --(*m_users);//increment amount of users after check and creating
        }
    }

    ~Chat() noexcept = default;

public:
    void run()
    {
        auto reader = std::thread(&Chat::read, this);

        write();
        reader.join();//join thread
        send_message(m_user_name + " left the chat");
        if (!(--(*m_users)))
        {
            m_shared_memory.destroy<vector_t>("Messages");
            m_shared_memory.destroy<mutex_t>("Mutex");
            m_shared_memory.destroy<condition_t>("Condition");
            m_shared_memory.destroy<counter_t>("Users");
            m_shared_memory.destroy<counter_t>("Messages");
            boost::interprocess::shared_memory_object::remove(shared_memory_name.c_str());
        }
    }

private:
    void read()
    {
        std::unique_lock<mutex_t> lock(*m_mutex);//added wrapper - do we need to use defer_lock?
        show_history();
        send_message(m_user_name + " joined the chat");
        auto cond = [this]() {return m_local_messages < *m_messages or m_exit_flag;};//condition of waiting
        while (true)
        {
            m_condition->wait(lock, cond);//rewrote more convenient way

            if (m_exit_flag)
            {
                break;//check if break
            }
            m_local_messages = *m_messages;
            std::cout << ???? << std::endl;//print new message
            ++m_local_messages;//increment
        }
    }

    void show_history()
    {
        boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(*m_mutex);//blocked mutex
        for (const auto& message : *m_vector)
        {
            std::cout << message.c_str() << std::endl;
        }
    }

    void send_message(const std::string& message)
    {
        boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(*m_mutex);//block mutex
        string_t message_ipc(message.begin(), message.end(), m_shared_memory.get_segment_manager());//transform type
        m_vector->push_back(message_ipc);
        ++(*m_messages);
        ++m_local_messages; //increment local messages
        m_condition->notify_all();//notify threads
    }

    void write()
    {
        while (!m_exit_flag)//cycle, until ctrl+z
        {
            std::cout << m_user_name << ": "; //input user + message
            std::string message;
            std::getline(std::cin, message);
            send_message(message); //send to chat
        }
        m_exit_flag = true; //flag for exit
    }

private:
    const std::string shared_memory_name = "shared_memory";

private:
    std::string m_user_name;
    std::atomic<bool> m_exit_flag;
    shared_memory_t m_shared_memory;

    vector_t* m_vector;
    mutex_t* m_mutex;
    condition_t* m_condition;
    counter_t* m_users;
    counter_t* m_messages;
    std::size_t m_local_messages = 0;
};

int main(int argc, char** argv)
{
    std::string user_name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, user_name);

    Chat(user_name).run();

    system("pause");

    return EXIT_SUCCESS;
}