#include "House.hpp"

int main() {
    House Dorm1("FRTK", 2, 3, House::C);
    House Dorm2("FIVT", 3, 2, House::C);
    House Dorm3("FAKI", 4, 4, House::C);
    House Dorm4("INO", 5, 30, House::C);
    House Dorm5("PROFI", 6, 7, House::C);
    House Dorm6("FOPF", 2, 2, House::B);
    House Dorm7("FUPM", 3, 4, House::B);
    House Dorm8("FEFM", 9, 20, House::B);
    House Dorm9("DIFF", 5, 5, House::A);
    House Dorm10("TEACH", 1, 1, House::A);
    House Dorm11("FPFE", 2, 2, House::A);
    House Dorm12("EVERYONE", 5, 3, House::A);

    Dorm8.printRooms();
    std::cout << std::endl;
    Dorm8.printInfo();
    std::cout << std::endl;

    return 0;
}