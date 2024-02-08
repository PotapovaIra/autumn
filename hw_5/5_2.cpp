#include <iostream>

class Example {
public:
    static int count;
    Example() {
        count++;
    }
    static int getCount() {
        return count;
    }
    ~Example() {
        count--;
    }
};
int Example::count = 0;

int main() {
    auto Ex1 = Example();
    auto Ex2 = Example();
    auto Ex3 = Example();
    auto Ex4 = Example();
    auto Ex5 = Example();

    std::cout << "Counted: " << Example::getCount() << std::endl;
    return 0;
}
