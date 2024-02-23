#include <iostream>
#include <vector>

int main() {
    std::vector<int> vectr;

    std::cout << "Initial Capacity: " << vectr.capacity() << std::endl;

    for (auto i = 33; i < 70; i++) {
        vectr.push_back(i);
        std::cout << "Capacity: " << vectr.capacity();
        if (vectr.capacity() > vectr.size()) {
            std::cout << " (Increased: " << vectr.capacity() / vectr.size() << " times)";
        }
        std::cout << std::endl;
    }

    return 0;
}
