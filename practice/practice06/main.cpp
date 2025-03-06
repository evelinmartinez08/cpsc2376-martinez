#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

int main() {
    Fraction currentFraction;

    while (true) {
        std::cout << "Current Fraction: " << currentFraction << std::endl;

        std::cout << "Options:\n";
        std::cout << "1. Enter a fraction manually\n";
        std::cout << "2. Add a fraction\n";
        std::cout << "3. Subtract a fraction\n";
        std::cout << "4. Multiply by a fraction\n";
        std::cout << "5. Divide by a fraction\n";
        std::cout << "6. Display as Mixed Fraction\n";
        std::cout << "7. Clear Fraction\n";
        std::cout << "8. Exit\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int num, den;
            std::cout << "Enter numerator and denominator: ";
            std::cin >> num >> den;
            try {
                currentFraction = Fraction(num, den);
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        } else if (choice >= 2 && choice <= 5) {
            int num, den;
            std::cout << "Enter numerator and denominator of the other fraction: ";
            std::cin >> num >> den;
            Fraction newFraction(num, den);
            try {
                if (choice == 2) {
                    currentFraction = currentFraction + newFraction;
                } else if (choice == 3) {
                    currentFraction = currentFraction - newFraction;
                } else if (choice == 4) {
                    currentFraction = currentFraction * newFraction;
                } else if (choice == 5) {
                    currentFraction = currentFraction / newFraction;
                }
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        } else if (choice == 6) {
            MixedFraction mixed(currentFraction);
            std::cout << "Mixed Fraction: " << mixed << std::endl;
        } else if (choice == 7) {
            currentFraction = Fraction();
        } else if (choice == 8) {
            break;
        }
    }

    return 0;
}
