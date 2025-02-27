#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int n, value;

    std::cout << "Enter the number of integers: ";
    std::cin >> n;

    std::cout << "Enter " << n << "integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        numbers.push_back(value);
    }

    std::cout << "Numbers in reverse order: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}