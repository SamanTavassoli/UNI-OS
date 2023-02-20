#include <iostream>

namespace first_namespace {
    void test() {
        std::cout << "test() called in first namespace" << std::endl;
    }
}

namespace second_namespace {
    void test() {
        std::cout << "test() called in second namespace" << std::endl;
    }
}