#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    std::string text;
    std::cout << "Enter some words or sentences: ";
    std::getline(std::cin, text);

    for (int i = 0; i < text.length(); i++) { //Убрать все знаки препинания
        if (ispunct(text[i])) {
            text.erase(i--, 1);
        }
    }

    std::vector<std::string> w1; //Поделили текст на слова
    std::string word;
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            w1.push_back(word);
            word = "";
        }
        else {
            word += text[i];
        }
    }
    w1.push_back(word);

    std::vector<std::string>mas_1;//Убрали повторки
    for (std::string word : w1) {
        bool found = false;
        for (std::string x : mas_1) {
            if (word == x) {
                found = true;
                break;
            }
        }
        if (!found) {
            mas_1.push_back(word);
        }
    }

    std::vector<int> freqs(mas_1.size()); // Посчитали частоту
    for (int i = 0; i < mas_1.size(); i++) {
        int count = 0;
        for (int j = 0; j < w1.size(); j++) {
            if (mas_1[i] == w1[j]) {
                count++;
            }
        }
        freqs[i] = count;
    }

    std::cout << "Words:"; //Результаты
    for (std::string word : mas_1) {
        std::cout << word << std::endl;
    }

    std::cout << "Percentage of each word:";
    for (int freq : freqs) {
        auto percent = (double)freq / w1.size() * 100;
        std::cout << percent << std::endl;
    }

    return 0;
}