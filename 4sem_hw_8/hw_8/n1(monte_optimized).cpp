#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <algorithm>
#include <thread>
#include <vector>
#include <functional>
#include <mutex>

struct Point
{
    double x;
    double y;
};
//do mutex
std::mutex mutex;
//generate points
Point generate()
{
    static constexpr std::size_t numInstances = 100'000;
    std::mt19937_64 gen(static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    Point point;
    point.x = dist(gen);
    point.y = dist(gen);

    return point;
}

//parallel version
double monte_parallel(int n, int num_threads){
    auto points = 0;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i)
    {
        threads.push_back(std::thread([&points, n, num_threads]()
            {
                auto points1 = 0;

                for (int i = 0; i < n / num_threads; ++i)
                {
                    Point point = generate();
                    if (point.x * point.x + point.y * point.y <= 1.0)
                    {
                        mutex.lock();
                        points1++;
                        mutex.unlock();
                    }
                }
                mutex.lock();
                points += points1;
                mutex.unlock();
            }));
    }

    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    return 4.0*points/n;
}

int main()
{
    auto n = 1000000;
    auto pi2 = monte_parallel(n,4);

    std::cout << "Parallel pi: " << std::setprecision(10) << pi2 << std::endl;

    return 0;

}