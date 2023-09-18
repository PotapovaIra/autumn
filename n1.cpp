#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
    std::string text;
    std::cout << "Enter some words or sentences: ";
    std::getline(std::cin, text);


    std::vector<std::string> w1; //Cut the sentence
    std::string word;
    for (const auto& c : text) {
        if (c == ' ') {
            w1.push_back(word);
            word = "";
        }
        else if (std::isalpha(c)) {
            word += c;
        }
    }
    w1.push_back(word);

    std::vector<std::string>mas_1;//Delete extra
    for (const std::string& word : w1) {
        bool found = false;
        for (std::string& x : mas_1) {
            if (word == x) {
                found = true;
                break;
            }
        }
        if (!found) {
            mas_1.push_back(word);
        }
    }

    std::vector<int> freqs(mas_1.size()); // Count frequency
    for (int i = 0; i < mas_1.size(); i++) {
        int count = 0;
        for (int j = 0; j < w1.size(); j++) {
            if (mas_1[i] == w1[j]) {
                count++;
            }
        }
        freqs[i] = count;
    }

    std::cout << "Words:"; //Results
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