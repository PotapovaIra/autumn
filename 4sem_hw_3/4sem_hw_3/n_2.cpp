#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include <chrono>
#include <random>
#include <algorithm>
#include <boost/functional/hash.hpp>


struct Fields {
    double doubl1;
    double doubl2;
    double doubl3;
};

int main(int argc, char** argv)
{
    // better to be as more as possible
    constexpr std::size_t size = 100'000;
    constexpr auto min_int = -100000;
    constexpr auto max_int = 100000;

    auto gen = std::mt19937_64(std::chrono::system_clock::now().time_since_epoch().count());
    auto dist = std::uniform_real_distribution<double>(min_int, max_int); 

    //auto vec = std::vector<double>(size, 0.0);
    //std::generate(std::begin(vec), std::end(vec), [&gen, &dist]() { return dist(gen); });

    std::unordered_set<std::size_t> hashCodes;
    int numCollisions = 0;
    const auto numExamples = 10000000;

    for (int i = 0; i < numExamples; i++)
    {
        Fields field;
        field.doubl1 = dist(gen);
        field.doubl2 = dist(gen);
        field.doubl3 = dist(gen);

        std::size_t hashCode = 0;
        boost::hash_combine(hashCode, field.doubl1);
        boost::hash_combine(hashCode, field.doubl2);
        boost::hash_combine(hashCode, field.doubl3);

        int prevSize = hashCodes.size();
        hashCodes.insert(hashCode);
        int currentSize = hashCodes.size();

 //       auto collision = size - currentSize;
        if (prevSize >= currentSize) {
            numCollisions++;; //Increment collision count if the size didn't increase
        }
        //std::cout << "Number of Examples: " << i + 1 << std::endl;
        //std::cout << numCollisions << std::endl;
        std::cout << numCollisions << std::endl;
        //std::cout << currentSize << std::endl;" " << numCollisions <<

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