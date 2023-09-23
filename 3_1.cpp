#include <iostream>
#include <vector>

int fibon(const int n);

int main() {
    auto n = 0;
    std::cin >> n;
    std::cout << fibon(n) << std::endl;
    return 0;
}

int fibon(const int n) {
    std::vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}