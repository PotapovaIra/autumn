#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <random>

class Timer
{
public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;

private:
	time_point_t m_begin;
	bool m_running;
	std::chrono::microseconds m_total;

public:
	Timer() : m_begin(clock_t::now()), m_running(false), m_total(std::chrono::microseconds(0)) {}

	~Timer() noexcept
	{
		if (m_running)
			stop();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds>(clock_t::now() - m_begin).count() << " microseconds" << std::endl;
		//std::cout << "total time: " << m_total.count() << " microseconds" << std::endl;
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

	void continu()
	{
		if (!m_running)
		{
			m_running = true;
			m_begin = clock_t::now();
		}
	}
};
static constexpr std::size_t SIZE = 10000;
int main() 
{
	//std::set
	{
		Timer timer;
		std::set<int> set;
		std::random_device rd;
		//use random numbers
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, SIZE);//https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
		for (auto i = 0; i < SIZE; ++i)
			set.insert(dis(gen));

	}
	//std:vector
	{
		Timer timer;
		std::vector<int> vec;
		std::random_device rd;
		//use random numbers
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, SIZE);

		for (auto i = 0; i < SIZE; i++)
			vec.push_back(dis(gen));

		std::sort(vec.begin(), vec.end());
	}
	return 0;
}



	
