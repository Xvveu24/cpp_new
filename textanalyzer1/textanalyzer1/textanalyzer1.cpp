#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>

int main() {
    std::setlocale(LC_ALL, "Ukrainian");

    std::cout << "Введіть текст для аналізу: ";
    std::string text;
    std::getline(std::cin, text);

    std::stringstream ss(text);
    std::string raw_word;
    std::map<std::string, int> word_counts;

    while (ss >> raw_word) {
        std::string processed_word = "";

        for (char c : raw_word) {
            unsigned char uc = static_cast<unsigned char>(c);
            if (std::isalnum(uc) || c == '+' || (uc >= 128)) {
                processed_word += std::tolower(uc);
            }
        }

        if (!processed_word.empty()) {
            word_counts[processed_word]++;
        }
    }

    if (word_counts.empty()) {
        std::cout << "Текст не містить слів для аналізу.\n";
        return 0;
    }

    std::cout << "\n--- Частота слів (за алфавітом) ---\n";
    std::string most_frequent_word = "";
    int max_count = 0;

    for (const auto& pair : word_counts) {
        std::cout << pair.first << " -> " << pair.second << '\n';

        if (pair.second > max_count) {
            max_count = pair.second;
            most_frequent_word = pair.first;
        }
    }

    std::cout << "\nНайчастіше слово: \"" << most_frequent_word
        << "\" (зустрічається " << max_count << " раз(и))\n";

    return 0;
}