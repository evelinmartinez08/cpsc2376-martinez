#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int n, value;

    std::cout << "Enter the number of integers: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        numbers.push_back(value);
    }

    std::cout << "Squared values: ";
    std::for_each(numbers.begin(), numbers.end(), [](int x) {
        std::cout << x * x << " ";
    });
    std::cout << std::endl;

    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int x) {
        return sum + (x * x);
    });

    std::cout << "Sum of squared values: " << sum_of_squares << std::endl;

    return 0;
}
