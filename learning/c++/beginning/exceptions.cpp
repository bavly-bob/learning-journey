#include <iostream>
#include <stdexcept> // Required for standard exceptions

int main() {
    double numerator, denominator, result;

    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;

    try {
        // Check for division by zero
        if (denominator == 0) {
            throw std::runtime_error("Math error: Attempted to divide by zero!");
        }

        result = numerator / denominator;
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::runtime_error& e) {
        // This block runs only if an error was "thrown"
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << "Program continues execution..." << std::endl;
    return 0;
}