#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <algorithm>
#include <thread>
#include <vector>
#include <functional>

struct Point
{
    double x;
    double y;
};
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
//sequent version
double monte_sequent(int n){
    auto points = 0;
    for (int i = 0; i < n; ++i)
    {
        auto point = generate();
        if (point.x*point.x + point.y*point.y <= 1.0)
        {
            points++;
        }
    }

    return 4.0 * points / n;
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
                for (int i = 0; i<n/num_threads; ++i)
                {
                    Point point = generate();
                    if (point.x*point.x + point.y*point.y <= 1.0)
                    {
                        points1++;
                    }
                }
                points += points1;
            }));
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    return 4.0*points/n;
}
int main(){
    auto n = 1000000;
    auto pi1 = monte_sequent(n);
    auto pi2 = monte_parallel(n, 4);
    std::cout << "Parallel pi: " << std::setprecision(10) << pi2 << std::endl;
    std::cout << "Sequent pi: " << std::setprecision(10) << pi1 << std::endl;
    return 0;

}