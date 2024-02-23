#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <chrono>

class Timer
{
public:
    using clock_t = std::chrono::steady_clock;
    using time_point_t = clock_t::time_point;

public:
    Timer(const std::string& operation) : m_begin(clock_t::now()), m_running(false), m_total(std::chrono::microseconds(0)), m_oper(operation)
    {}

    ~Timer() noexcept
    {
        if (m_running)
            stop();
        std::cout << "Time for " << m_oper << ": " << m_total.count() << " microseconds" << std::endl;
    }

    void start()
    {
        if (!m_running)
        {
            m_running = true;
            m_begin = clock_t::now();
        }
    }

    void stop()
    {
        if (m_running)
        {
            m_total += std::chrono::duration_cast<std::chrono::microseconds>(clock_t::now() - m_begin);
            m_running = false;
        }
    }

private:
    time_point_t m_begin;
    bool m_running;
    std::chrono::microseconds m_total;
    std::string m_oper;
};

int main()
{
    const int size = 1000000; // container size

    std::array<int, size> arr;
    std::vector<int> vec(size);
    std::deque<int> deq(size);
    std::list<int> lst(size);
    std::forward_list<int> forwardlst(size);

  
    for (int i = 0; i < size; ++i)
    {
        arr[i] = i;
        vec[i] = i;
        deq[i] = i;
        lst.push_back(i);
        forwardlst.push_front(i);
    }

    Timer t_arr("std::array sorting");
    t_arr.start();
    std::sort(arr.begin(), arr.end());
    t_arr.stop();

    Timer t_vec("std::vector sorting");
    t_vec.start();
    std::sort(vec.begin(), vec.end());
    t_vec.stop();

    Timer t_deq("std::deque sorting");
    t_deq.start();
    std::sort(deq.begin(), deq.end());
    t_deq.stop();

    Timer t_lst("std::list sorting");
    t_lst.start();
    lst.sort();
    t_lst.stop();

    Timer t_forwardlst("std::forward_list sorting");
    t_forwardlst.start();
    forwardlst.sort();
    t_forwardlst.stop();


    return 0;
}