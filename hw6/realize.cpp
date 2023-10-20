#include "inter.hpp"

Class::Class() : mas(nullptr), sizemas(0) {}

Class::Class(const Class& other) : mas(new int[other.sizemas]), sizemas(other.sizemas), v(other.v) {
    for (int i = 0; i < sizemas; i++) {
        mas[i] = other.mas[i];
    }
}

Class::Class(Class&& other) : mas(other.mas), sizemas(other.sizemas), v(std::move(other.v)) {
    other.mas = nullptr;
    other.sizemas = 0;
}

Class::~Class() {
    delete[] mas;
}

Class& Class::operator=(const Class& other) {
    if (this != &other) {
        delete[] mas;
        mas = new int[other.sizemas];
        sizemas = other.sizemas;
        v = other.v;
        for (int i = 0; i < sizemas; i++) {
            mas[i] = other.mas[i];
        }
    }
    return *this;
}

Class& Class::operator=(Class&& other) {
    if (this != &other) {
        delete[] mas;
        mas = other.mas;
        sizemas = other.sizemas;
        v = std::move(other.v);
        other.mas = nullptr;
        other.sizemas = 0;
    }
    return *this;
}