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
    auto sortRemain = [](int a, int b) {
        if (a % 3 == b % 3) { // if remainders are equal
            return a < b; // sort by value
        }
        return a % 3 < b % 3; // otherwise sort by remainder
        };
    std::sort(mas.begin(), mas.end(), sortRemain); //by remainder

    std::cout << "Sorted by remainder: ";
    for (const auto& el : mas) {
        std::cout << el << " ";
    }
    std::cout << std::endl;


    return 0;
}