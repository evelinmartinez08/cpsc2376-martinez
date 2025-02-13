#include <iostream>
#include <string>

template <typename T>
T findMax(T a, T b, T c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main() {
    int choice;
    std::cout << "Compare (1) Numbers or (2) Strings? ";
    std::cin >> choice;

    if (choice == 1) {
        int a, b, c;
        std::cout << "Enter first value: ";
        std::cin >> a;
        std::cout << "Enter second value: ";
        std::cin >> b;
        std::cout << "Enter third value: ";
        std::cin >> c;
        std::cout << "Max value: " << findMax(a, b, c) << "\n";

    } else if (choice == 2) {
        std::string a, b, c;
        std::cout << "Enter first value: ";
        std::cin.ignore();
        std::getline(std::cin, a);
        std::cout << "Enter second value: ";
        std::getline(std::cin, b);
        std::cout << "Enter third value: ";
        std::getline(std::cin, c);
        std::cout << "Max value: " << findMax(a, b, c) << "\n";

    } else {
        std::cout << "Invalid choice!\n";
    }

    return 0;
}
