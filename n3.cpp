#include <iostream>
#include <vector>
#include <limits>


int bin(vector<int>mas, int x) { //х-то, что ищем
    auto l = 0;
    auto r = mas.size() - 1; // преобразуем size_t в int

    while (l <= r) {
        auto middle = l + (r - l) / 2;

        if (mas[middle] == x) {

            while (middle > 0 && mas[middle - 1] == x) { //первое вхождение
                middle--;
            }
            return middle;
        }
        else if (mas[middle] < x) {
            l = middle + 1;
        }
        else {
            r = middle - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> mas = {1,2,3,4,5,5,6,7,8};
    auto x = 5;

    auto n = bin(mas, x);

    if (n == -1) {
        std::cout << "No such index x"<<std::endl;
    }
    else {
        std::cout << "x is situated at index " << n << std::endl;
    }

    return 0;
}