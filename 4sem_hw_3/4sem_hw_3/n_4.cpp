#include <iostream>
#include <string>
#include <unordered_set>
#include <chrono>
#include <random>
#include <algorithm>
#include <boost/functional/hash.hpp>
#include <vector>

struct Fields {
    double doubl1;
    double doubl2;

    bool operator==(const Fields& other) const {
        return (doubl1 == other.doubl1) && (doubl2 == other.doubl2);
    }
};

namespace std {
    template<> struct hash<Fields> {
        std::size_t operator()(const Fields& f) const {
            std::size_t seed = 0;
            boost::hash_combine(seed, f.doubl1);
            boost::hash_combine(seed, f.doubl2);
            return seed;
        }
    };
}

int main(int argc, char** argv)
{
    constexpr std::size_t numInstances = 100'000;
    std::mt19937_64 gen(static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> dist(-100.0, 100.0);

    std::vector<Fields> instances;
    std::unordered_set<std::size_t> hashCodes;

    for (std::size_t i = 0; i < numInstances; ++i) {
        Fields field;
        field.doubl1 = dist(gen);
        field.doubl2 = dist(gen);
        instances.push_back(field);

        std::size_t hashCode = std::hash<Fields>{}(field);
        hashCodes.insert(hashCode);

        std::cout << hashCodes.size() << "," << i + 1 << std::endl;
    }

    return 0;
}