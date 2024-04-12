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
        m_shared_memory(boost::interprocess::create_only, shared_memory_name.c_str(), 65536)
    {
        m_vector = m_shared_memory.construct<vector_t>("Messages")(m_shared_memory.get_segment_manager());
        m_mutex = m_shared_memory.construct<mutex_t>("Mutex")();
        m_condition = m_shared_memory.construct<condition_t>("Condition")();
        m_users = m_shared_memory.construct<counter_t>("Users")(1);
        m_messages = m_shared_memory.construct<counter_t>("Messages")(0);
    }

    ~Chat() noexcept = default;

public:
    void run()
    {
        auto reader = std::thread(&Chat::read, this);

        write();

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
        show_history();
        send_message(m_user_name + " joined the chat");

        while (true)
        {

            for (std::size_t i = m_local_messages; i < *m_messages; ++i)
            {
                std::cout << (*m_vector)[i].c_str() << std::endl;
            }

            m_local_messages = *m_messages;
        }
    }

    void show_history()
    {
        for (const auto& message : *m_vector)
        {
            std::cout << message.c_str() << std::endl;
        }
    }

    void send_message(const std::string& message)
    {
        boost::interprocess::scoped_lock<boost::interprocess::interprocess_mutex> lock(*m_mutex);
        ++(*m_messages);
    }

    void write()
    {
        ...
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