#include <iostream>
#include <vector>
#include <algorithm>

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

    auto maxIt = std::max_element(numbers.begin(), numbers.end());
    auto minIt = std::min_element(numbers.begin(), numbers.end());

    std::cout << "Largest element: " << *maxIt << std::endl;
    std::cout << "Smallest element: " << *minIt << std::endl;

    return 0;
}