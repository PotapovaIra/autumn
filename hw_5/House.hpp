#include <iostream>
#include <string>
#include <vector>

class House {
public:
    enum HouseType {
        B,
        C,
        A,
        Unknown
    };
    std::string faculty;
    int floors;
    int rooms;
    HouseType type;

    House(const std::string& fac, int flrs, int r, const HouseType& tp);
    ~House();
    void printInfo();
    void printRooms();
};
