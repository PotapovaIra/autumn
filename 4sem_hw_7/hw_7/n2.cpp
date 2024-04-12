#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include <iomanip>

template<typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result)
    {
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init, int num_threads)
{
    const auto length = std::distance(first, last);

    if (length == 0)
        return init;

    const std::size_t block_size = length / num_threads;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);

    Iterator block_start = first;

    for (std::size_t i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);

        threads[i] = std::thread(
            accumulate_block<Iterator, T>(),
            block_start, block_end, std::ref(results[i]));

        block_start = block_end;
    }

    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    for (auto& thread : threads)
    {
        if (thread.joinable())
            thread.join();
    }

    return std::accumulate(results.begin(), results.end(), init);
}

class Timer
{
public:
    using clock_t = std::chrono::steady_clock;
    using time_point_t = clock_t::time_point;

    Timer() : m_begin(clock_t::now()), m_running(false), m_total(std::chrono::microseconds(0))
    {}

    ~Timer() noexcept
    {
        if (m_running)
            stop();
        std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(clock_t::now() - m_begin).count() << " microseconds" << std::endl;
    }

    void start() //run timer method
    {
        if (!m_running)
        {
            m_running = true;
            m_begin = clock_t::now();
        }
    }

    void stop() //stop timer method
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
    time_point_t m_pause;
    std::chrono::microseconds m_total;
};

int main()
{
    std::vector<long long> durations;
    std::vector<int> thread_counts = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}; //num of threads
    for (int num_threads : thread_counts)
    {
        std::cout << "Num threads: " << num_threads << std::endl;
        Timer timer;
        std::vector<int> v(10000000, 1);

        long long result = parallel_accumulate(v.begin(), v.end(), 0, num_threads);
        durations.push_back(result);
    }
}
