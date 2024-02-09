#include "inter.hpp"

int main() {
    Class a; // deafult constructor
    Class b(a); // copy constructor
    Class c(std::move(a)); // constructor move
    a = std::move(c); // operator of moving
    return 0;
}
