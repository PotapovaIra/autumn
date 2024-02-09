#include<iostream>
#include<string>

struct Book {
    std::string name;
    std::string author;
    int year;
    bool available;

    Book(std::string t, std::string a, int y) {
        name = t;
        author = a;
        year = y;
        available = true;

    }
    void borrow() {
        if (available) {
            std::cout << "The book " << name << " has been borrowed." << std::endl;
            available = false;

        }
        else {
            std::cout << "The book " << name << " is unavailable." << std::endl;

        }

    }
    void returnn() {
        if (!available) {
            std::cout << "The book " << name << " has been returned." << std::endl;
            available = true;

        }
        else {
            std::cout << "The book " << name << " was not borrowed." << std::endl;

        }

    }
    void printDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Year of public: " << year << std::endl;
        std::cout << "Availabie or not: ";
        if (available) {
            std::cout << "Available" << std::endl;
        }
        else {
            std::cout << "Not Available" << std::endl;

        }

    }

};

int main() {
    Book book1("Methods of solving problems in general physics", "V.P. Koryavov", 2021);
    Book book2("Electricity", "D.V.Sivuhin", 2006);
    Book book3("Collection of problems on math analysis, part3", "L.D.Kudryavtsev", 2003);
    book1.printDetails();
    book1.borrow();
    book1.borrow();
    book1.returnn();

    std::cout << std::endl;
    book2.printDetails();
    book2.borrow();
    book2.returnn();
    book2.returnn();
    std::cout << std::endl;

    book3.printDetails();
    book3.returnn();
    book3.borrow();
    book3.borrow();

    return 0;
}
