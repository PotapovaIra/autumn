#include <iostream>
#include <vector>

int partition(std::vector<int>& mas, int low, int high);
void quicksort(std::vector<int>& mas, int low, int high);


int partition(std::vector<int>& mas, int low, int high) {
    auto pivot = mas[low];
    auto i = low - 1;
    auto j = high + 1;
    while (i < j) {
        do {
            i++;
        } while (mas[i] < pivot);
        do {
            j--;
        } while (mas[j] > pivot);
        if (i < j) {
            std::swap(mas[i], mas[j]);
        }
    }
    return j;
}

void quicksort(std::vector<int>& mas, int low, int high) {
    if (low < 0 || high >= mas.size() || low >= high) {
        return;
    }
    auto p = partition(mas, low, high);
    quicksort(mas, low, p);
    quicksort(mas, p + 1, high);
}
int main() {
    std::vector<int> mas = { 1,82,8,18,28,45,4,5,90,45 };
    quicksort(mas, 0, mas.size() - 1);

    for (const auto& el : mas) {
        std::cout << el << " ";
    }

    return 0;
}
