#include <iostream>

int main(int argc, char** argv) {
    
    // Statically allocated array
    // Size be const for static array
    const int arraySize = 10;
    int myArray[arraySize];
    std::cout << "Static array size: " << sizeof(myArray) << " bytes" << std::endl;

    // Dynamically allocated array
    // Declare pointer
    int* dynamicArray;
    // Initialise pointer (we shouldn't use malloc anymore)
    dynamicArray = new int[arraySize];
    std::cout << "Dynamic array size: " << sizeof(dynamicArray) << " bytes" << std::endl;
    std::cout << "Can only get pointer's size, trickier to get dynamic array's size" << std::endl;

    // Remove dynamic allocations from heap
    // Note brackets for array (shouldn' use free anymore either)
    delete[] dynamicArray;

    return 0;
}