#include <iostream>
#include<chrono>
#include<vector>
#include<algorithm>
#include<numeric>
#include<execution>
#include <execution>


class Timer
{

public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;

public:
	Timer() : m_begin(clock_t::now()), m_running(false), m_total(std::chrono::microseconds(0))
	{}

	~Timer() noexcept
	{
		if (m_running)
			stop();
		std::cout << std::chrono::duration_cast <std::chrono::microseconds> (clock_t::now() - m_begin).count() << " microseconds" << std::endl;
		//std::cout << "total time: " << m_total.count() << " microseconds" << std::endl;
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
	void continu() //continue method
	{
		if (!m_running)
		{
			m_running = true;
			m_begin = clock_t::now() - std::chrono::duration_cast<clock_t::duration>(m_total);
		}
	}
	void pause() //make pause method
	{
		if (m_running)
		{
			m_total += std::chrono::duration_cast<std::chrono::microseconds>(clock_t::now() - m_begin);
			m_running = false;
		}
	}
	//void reset()
	//{
	//	m_total = 
	//}
private:
	time_point_t m_begin;
	bool m_running;
	time_point_t m_pause;
	std::chrono::microseconds m_total;
};

int main()
{
	{
		std::vector<int> data(1000000, 1);

		{
			std::cout << "Transform parallel realisation time: " << std::endl;
			Timer t;
			std::transform(std::execution::par, data.begin(), data.end(), data.begin(), [](int n) {
				return n * 5;
				});
		}

		{
			std::cout << "Transform sequential realisation time: " << std::endl;
			Timer t;
			std::transform(data.begin(), data.end(), data.begin(), [](int n) {
				return n * 5;
				});
		}

		{
			std::cout << "Sort parallel realisation time: " << std::endl;
			Timer t;
			std::sort(std::execution::par, data.begin(), data.end());
		}

		{
			std::cout << "Sort sequential realisation time: " << std::endl;
			Timer t;
			std::sort(data.begin(), data.end());
		}

		{
			std::cout << "Count parallel realisation time: " << std::endl;
			Timer t;
			int count_parallel = std::count(std::execution::par, data.begin(), data.end(), 2);
		}


		{
			std::cout << "Count sequential realisation time: " << std::endl;
			Timer t;
			int count_sequential = std::count(data.begin(), data.end(), 2);
		}
	}

	system("pause");

	return 0;
}