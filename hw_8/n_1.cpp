#include <iostream>
#include <exception>
#include <vector>
#include <cmath>

void test1() {
    std::vector<int> v(5);
    v(10) = 3;
}

void test2() {
    int a = 5, b = 0;
    int c = a / b;
}

void test3() {
    double x = -1;
    double y = sqrt(x);
}

void test4() {
    int arr[5] = { 1, 2, 3, 4, 5 };
    int& r = arr[10];
}

int main() {
    try {
        test1();
    }
    catch (std::out_of_range& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    try {
        test2();
    }
    catch (std::logic_error& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    try {
        test3();
    }
    catch (std::domain_error& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    try {
        test4();
    }
    catch (std::out_of_range& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    return 0;
}
