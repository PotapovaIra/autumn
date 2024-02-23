#include <iostream>
#include <vector>

int main() {
    std::vector<int> vectr;

    std::cout << "Initial Capacity: " << vectr.capacity() << std::endl;

    vectr.reserve(1000);

    std::cout << "Capacity after reserve: " << vectr.capacity() << std::endl;

    return 0;
}