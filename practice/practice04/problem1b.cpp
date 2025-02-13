#include <iostream>
#include <string>

void greet(std::string name = "Guest", std::string prefix = "Hello") {
    std::cout << prefix << ", " << name << "!\n";
}

int main() {
    int choice;
    
    while (true) {
        std::cout << "\n1. Default Greeting\n";
        std::cout << "2. Greet by Name\n";
        std::cout << "3. Custom Greeting\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            greet();

        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            greet(name);

        } else if (choice == 3) {
            std::string prefix, name;
            std::cout << "Enter greeting prefix: ";
            std::cin.ignore();
            std::getline(std::cin, prefix);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            greet(name, prefix);

        } else if (choice == 4) {
            std::cout << "Goodbye!\n";
            break;

        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
