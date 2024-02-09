#include <iostream>
#include<chrono>

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
		std::cout << "total time: " << m_total.count() << " microseconds" << std::endl;
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
		Timer t;

		auto x = 1.0;

		for (auto i = 0; i < 1'000'000'000; ++i)
		{
			x += 1.23;
		}
		t.stop();

		t.start();
		t.pause();
		t.continu();
		//t.reset();
	}

	system("pause");

	return EXIT_SUCCESS;
}
