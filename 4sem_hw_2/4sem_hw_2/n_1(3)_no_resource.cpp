#include <iostream>
#include <vector>

int main() {
    std::vector<int> vectr;

    // Запрашиваем большое количество памяти
    vectr.reserve(1000000000); // 1 миллиард элементов

    // Пытаемся добавить элементы, чтобы увеличить размер вектора
    for (auto i = 0; i < 1000; i++) {
        vectr.push_back(i);
    }

    // Пробуем добавить еще один элемент
    try {
        vectr.push_back(1001);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}