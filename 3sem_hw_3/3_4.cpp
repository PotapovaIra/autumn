#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>


double calculate(double a, double b, std::function<double(double, double)> func);

int main() {
    std::unordered_map<std::string, std::function<double(double, double)>> funcs = {
        {"add", [](double a, double b) { return a + b; }},
        {"subtract", [](double a, double b) { return a - b; }},
        {"multiply", [](double a, double b) { return a * b; }},
        {"divide", [](double a, double b) { return a / b; }},
        {"sum of squeares", [](double a, double b) { return a * a + b * b; }},
        {"a more th b", [](double a, double b) { return a > b; }}
    };

    std::vector<std::pair<double, double>> pairs = { {1.82, 8.18}, {2.84, 1.09}, {4.69, 5.55} };

    for (const auto& pair : pairs) {
        std::cout << "Pair: " << pair.first << ", " << pair.second << std::endl;
        for (const auto& func : funcs) {
            std::cout << func.first << ": " << calculate(pair.first, pair.second, func.second) << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}

double calculate(double a, double b, std::function<double(double, double)> func) {
    return func(a, b);
}
