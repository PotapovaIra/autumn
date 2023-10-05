#include "House.hpp"

House::House(const std::string& fac, int flrs, int r, const HouseType& tp) {
    faculty = fac;
    floors = flrs;
    rooms = r;
    type = tp;
}

House::~House() {
    std::cout << "House " << faculty << " destroyed." << std::endl;
}

void House::printInfo() {
    std::cout << "Faculty: " << faculty << std::endl;
    std::cout << "Floors: " << floors << std::endl;
    std::cout << "Rooms per floor: " << rooms << std::endl;
    std::cout << "Type: ";
    switch (type) {
    case HouseType::B:
        std::cout << "Block house";
        break;
    case HouseType::C:
        std::cout << "Corridor house";
        break;
    case HouseType::A:
        std::cout << "Apartment house";
        break;
    default:
        std::cout << "Unknown type";
    }
    std::cout << std::endl;
}

void House::printRooms() {
    for (int i = 1; i <= floors; i++) {
        std::cout << "Floor " << i << ":" << std::endl;
        for (int j = 1; j <= rooms; j++) {
            std::cout << "Room " << j << std::endl;
        }
    }
}

