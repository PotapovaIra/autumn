#include <iostream>
#include <vector>

int partition(std::vector<int>& mas, int low, int high) {
    auto pivot = mas[(low + high) / 2];
    auto i = low;
    auto j = high;
    while (true) {
        while (mas[i] <= pivot) {
            i++;
        }
        while (mas[j] >= pivot) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        std::swap(mas[i++], mas[j--]);
    }
}

void quicksort(std::vector<int>& mas, int low, int high) {
    if (low < high) {
        auto p = partition(mas, low, high);
        quicksort(mas, low, p - 1);
        quicksort(mas, p + 1, high);
    }
}
int main() {
    std::vector<int> mas = { 3,1,4,1,5,9,2,6,5,3,5 };
    quicksort(mas, 0, mas.size() - 1);

    for (const auto& el : mas) {
        std::cout << el << " ";
    }

    return 0;
}