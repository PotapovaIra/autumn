#include <iostream>
#include <string>
#include <vector>

struct House {
    std::string faculty;
    int floors;
    int rooms;
    std::string type;

    House(const std::string& fac, const int& flrs, const int& r, const std::string& tp) {
        faculty = fac;
        floors = flrs;
        rooms = r;
        type = tp;
    }

    ~House() {
        std::cout << "House " << faculty << " destroyed." << std::endl;
    }

    int printInfo() {
        std::cout << "Faculty: " << faculty << std::endl;
        std::cout << "Floors: " << floors << std::endl;
        std::cout << "Rooms per floor: " << rooms << std::endl;
        std::cout << "Type: " << type << std::endl;
    }

    int printRooms() {
        for (int i = 1; i <= floors; i++) {
            std::cout << "Floor " << i << ":" << std::endl;
            for (int j = 1; j <= rooms; j++) {
                std::cout << "Room " << j << std::endl;
            }
        }
    }

    int printType() {
        switch (type[0]) {
        case 'B':
            std::cout << "Block house" << std::endl;
            break;
        case 'C':
            std::cout << "Corridor house" << std::endl;
            break;
        case 'A':
            std::cout << "Apartment house" << std::endl;
            break;
        default:
            std::cout << "Unknown type" << std::endl;
        }
    }
};

int main() {
    House Dorm1("FRTK", 2, 3, "C");
    House Dorm2("FIVT", 3, 2, "C");
    House Dorm3("FAKI", 4, 4, "C");
    House Dorm4("INO", 5, 30, "C");
    House Dorm5("PROFI", 6, 7, "C");
    House Dorm6("FOPF", 2, 2, "B");
    House Dorm7("FUPM", 3, 4, "B");
    House Dorm8("FEFM", 9, 20, "B");
    House Dorm9("DIFF", 5, 5, "A");
    House Dorm10("TEACH", 1, 1, "A");
    House Dorm11("FPFE", 2, 2, "A");
    House Dorm12("EVERYONE", 5, 3, "A");

    Dorm8.printRooms();
    std::cout << std::endl;
    Dorm8.printInfo();
    std::cout << std::endl;
    Dorm8.printType();

    return 0;
}