#include <iostream>

// This template function finds the larger of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Works with integers
    std::cout << "Max of 10 and 20: " << findMax(10, 20) << std::endl;

    // Works with floating point numbers
    std::cout << "Max of 5.5 and 2.2: " << findMax(5.5, 2.2) << std::endl;

    // Works with characters
    std::cout << "Max of 'g' and 'z': " << findMax('g', 'z') << std::endl;

    return 0;
}