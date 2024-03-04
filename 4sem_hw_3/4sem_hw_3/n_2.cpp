#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>
#include <boost/functional/hash.hpp>
#include <vector>

struct Fields {
    double int1;
    double doubl1;
    double doubl2;
};

int main(int argc, char** argv)
{
    // better to be as more as possible
    constexpr std::size_t size = 100'000;
    constexpr auto min_int = -100;
    constexpr auto max_int = 100;

    auto gen = std::mt19937_64(std::chrono::system_clock::now().time_since_epoch().count());
    auto dist = std::uniform_real_distribution<double>(min_int, max_int); // исправлено

    auto vec = std::vector<double>(size, 0.0);
    std::generate(std::begin(vec), std::end(vec), [&gen, &dist]() { return dist(gen); });

    std::unordered_set<std::size_t> hashCodes;
    int numCollisions = 0;
    const auto numExamples = 1000;

    for (int i = 0; i < numExamples; i++)
    {
        Fields field;
        field.int1 = std::uniform_int_distribution<int>(-100, 100)(gen);
        field.doubl1 = dist(gen); // исправлено
        field.doubl2 = dist(gen); // исправлено

        std::size_t hashCode = 0;
        boost::hash_combine(hashCode, field.int1);
        boost::hash_combine(hashCode, field.doubl1);
        boost::hash_combine(hashCode, field.doubl2);

        int prevSize = hashCodes.size();
        hashCodes.insert(hashCode);
        int currentSize = hashCodes.size();

        auto collision = vec.size() - hashCodes.size();
 //       std::cout << collision << std::endl;
        std::cout << currentSize << std::endl;

    }
    return 0;
}






//std::size_t hash(const char* s)
//{
//	auto h = 0U;
//
//	for (auto p = s; *p != '\0'; ++p)
//	{
//		h = h * 31 + static_cast <unsigned int> (*p);
//	}
//
//	return h % 128;
//}
//int main(int argc, char** argv)
//{
//	std::cout << hash("ivanov") << std::endl;
//
//	system("pause");
//
//	return EXIT_SUCCESS;
//}