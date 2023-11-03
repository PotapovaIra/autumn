#include <iostream>
#include <exception>


void test1() {
    throw std::runtime_error("Runtime error ");
}

void test2() {
    throw std::logic_error("Logic error");
}

void test3() {
    int* ptr = nullptr;
    *ptr = 10;
}


void test4() {
    throw std::out_of_range("Out of range error");
}

int main() {
    try {
        test1();
    }
    catch (std::exception& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    try {
        test2();
    }
    catch (std::exception& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    try {
        test3();
    }
    catch (std::exception& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    try {
        test4();
    }
    catch (std::exception& e) {
        std::cout << "Exception catch: " << e.what() << std::endl;
    }
    return 0;
}