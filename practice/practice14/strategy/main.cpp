#include <iostream>
#include <memory>
#include "TextProcessor.h"
#include "UppercaseFilter.h"
#include "RemoveVowelsFilter.h"

int main() {
    TextProcessor processor;
    std::string text;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, text);

    int choice;
    while (true) {
        std::cout << "\nChoose a filter:\n";
        std::cout << "1. Uppercase\n";
        std::cout << "2. Remove Vowels\n";
        std::cout << "3. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                processor.setStrategy(std::make_unique<UppercaseFilter>());
                std::cout << "Processed Text: " << processor.process(text) << std::endl;
                break;
            case 2:
                processor.setStrategy(std::make_unique<RemoveVowelsFilter>());
                std::cout << "Processed Text: " << processor.process(text) << std::endl;
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid choice, try again." << std::endl;
        }
    }
}
