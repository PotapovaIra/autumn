#include<iostream>


struct Date {
    int year : 12;//2^12 = 4096 > 2023
    int month : 4; //2^4 = 16 > 12
    int day : 5; //2^5=32 > 
    int hour : 5;
    int minute : 6;
    int second : 6;
    int millisecond : 10;
};
int main() {
    Date now = { 2021, 8, 23, 10, 30, 15, 500 };
    std::cout << "date: " << now.year << "-"
        << now.month << "-" << now.day << " " << now.hour << ":"
        << now.minute << ":" << now.second << "."
        << now.millisecond << std::endl;
}
