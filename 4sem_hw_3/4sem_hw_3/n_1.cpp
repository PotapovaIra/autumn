#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <random>
#include "Timer.h"

int main(int argc, char** argv)
{
    // better to be as more as possible
    constexpr std::size_t size = 100'000;

    // defines uniform distribution borders
    constexpr auto min_int = -100;
    constexpr auto max_int = 100;

    // create random generator with system clock seed
    auto gen = std::mt19937_64(std::chrono::system_clock::now().time_since_epoch().count());

    // you can choose other distribution if you want
    auto dist = std::uniform_int_distribution<int>(min_int, max_int);

    // create and generate vector
    auto vec = std::vector<int>(size, 0);

    std::generate(std::begin(vec), std::end(vec), [&gen, &dist]() { return dist(gen); });

    {
        Timer timer;
        std::set<int> mySet(vec.begin(), vec.end());
    }

    {
        Timer timer;
        std::sort(vec.begin(), vec.end());
    }


    return EXIT_SUCCESS;
}




	
