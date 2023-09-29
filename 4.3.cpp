#include <iostream>

struct Month {
    enum MonthName {
        JAN = 1, FEB, MAR, APRIL, MAY, JUNE,
        JULY, AUG, SEPT, OCT, NOV, DEC
    };
    int month;
    bool leapyear;
};

int getDays(const Month& m) {
    switch (m.month) {
    case Month::JAN:
    case Month::MAR:
    case Month::MAY:
    case Month::JULY:
    case Month::AUG:
    case Month::OCT:
    case Month::DEC:
        return 31;
    case Month::APRIL:
    case Month::JUNE:
    case Month::SEPT:
    case Month::NOV:
        return 30;
    case Month::FEB:
        if (m.leapyear) {
            return 29;
        }
        else {
            return 28;
        }
    default:
        return 0;
    }
}

int main() {
    auto m = Month();
    std::cout << "Enter month number: ";
    std::cin >> m.month;
    if (m.month > 12) {
        std::cout << "Wrong month number" << std::endl;
        return 0;
    }
    std::cout << "Is it a leap year? (1 for yes, 0 for no): ";
    auto fleapyear = 0;
    std::cin >> fleapyear;
    m.leapyear = static_cast<bool>(fleapyear);
    if (fleapyear != 0 && fleapyear != 1) {
        std::cout << "Wrong input for leap year" << std::endl;
        return 0;
    }
    auto days = getDays(m);
    if (days == 0) {
        std::cout << "Wrong month number" << std::endl;
    }
    else {
        std::cout << "There are " << days << " days in this month" << std::endl;
    }
    return 0;
}