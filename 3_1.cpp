#include <iostream>
#include <vector>

int main() {
    auto n = 0;
    std::cin >> n;
    std::vector<int> fib(n);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    std::cout << fib[n] << std::endl;
    return 0;
}
