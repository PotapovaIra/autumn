#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> mas = { 1,8,28,18,2,8,45,9,0,4,5 };

    auto sortBySquares = [](int a, int b) {
        return a * a < b * b;
        };

    std::sort(mas.begin(), mas.end(), sortBySquares);

    std::cout << "Sorted by squares: ";
    for (const auto& el : mas) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    auto sortAsc = [](int a, int b) {
        return a < b;
        };

    std::sort(mas.begin(), mas.end(), sortAsc);//in right way
    std::cout << "Sorted in direct way: ";
    for (const auto& el : mas) {
        std::cout << el << " ";
    }
    auto sortDesc = [](int a, int b) {
        return a > b;
        };
    std::sort(mas.begin(), mas.end(), sortDesc); //reversed
    std::cout << "Sorted in reversed way: ";
    for (const auto& el : mas) {
        std::cout << el << " ";
    }


    auto sortByMod = [](int mod) {
        return [mod](int a, int b) {
            return a % mod < b % mod;
            };
        };
    std::sort(mas.begin(), mas.end(), sortByMod);

    std::cout << "Sorted by remain: ";
    for (const auto& el : mas) {
        std::cout << el << " ";
    }
    std::cout << std::endl;


    auto sort_by_remainder = [](std::vector<int>& mas) {
        std::sort(mas.begin(), mas.end(), [](const int& a, const int& b) {
            return a % 3 < b % 3;
            });
        };

    std::cout << "Sorted by remain: ";
    for (const auto& el : mas) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    return 0;
}
