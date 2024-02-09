#include <iostream>
#include <vector>

void print(const std::vector<int>& mas)
{
    for (auto i : mas)
        std::cout << i << " ";
    printf("\n");
}

void gen(std::vector<int> mas, int size)
{
    if (size == 1) {
        print(mas);
        return;
    }

    for (auto i = 0; i < size; i++) {
        gen(mas, size - 1);
        if (size % 2 == 1)
            std::swap(mas[0], mas[size - 1]);
        else
            std::swap(mas[i], mas[size - 1]);
    }
}

int main()
{
    auto n = 0;
    std::cout << "Enter N: ";
    std::cin >> n;

    std::vector<int> mas(n + 1);
    for (auto i = 0; i <= n; i++)
        mas[i] = i;

    gen(mas, n + 1);
    return 0;
}