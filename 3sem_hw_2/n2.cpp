#include <iostream>
#include <vector>

void select(std::vector<int>& mas) {
    auto n = mas.size();
    for (int i = 0; i < n - 1; i++) {
        int compare = i;
        for (int j = i + 1; j < n; j++) {
            if (mas[j] < mas[compare]) {
                compare = j;
            }
        }
        if (compare != i) {
            std::swap(mas[i], mas[compare]);
        }
    }
}

int main() {
    std::vector<int> mas = {13,11,9,14,17,6};
    select(mas);
    for (int i:mas) {
        std::cout << i;
    }
    std::cout << std::endl;
    return 0;
}
