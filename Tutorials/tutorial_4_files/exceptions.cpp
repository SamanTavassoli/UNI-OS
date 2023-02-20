#include <iostream>
#include <stdexcept>

double dividNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::exception();
    }

    return numerator / denominator;
}

int main(int argc, char** argv) {
    try {
        std::cout << dividNumbers(2.5, 0.5) << std::endl;
        std::cout << dividNumbers(2.5, 0) << std::endl;
    } catch (std::exception e) {
        std::cout << "Caught an exception!" << std::endl;
    }
}