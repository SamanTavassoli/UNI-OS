#include <iostream>
#include <typeinfo>

int main(int argc, char** argv) {

    // Using \t to add tabs to line up results
    std::cout << "size of char: \t\t\t" << sizeof(char) << " bytes" << std::endl;
    std::cout << "size of short [int optional]: \t" << sizeof(short) << " bytes" << std::endl;
    std::cout << "size of int: \t\t\t" << sizeof(int) << " bytes" << std::endl;
    std::cout << "size of long [int optional]: \t" << sizeof(long) << " bytes" << std::endl;
    std::cout << "size of long long [int optional]: " << sizeof(long long) << " bytes" << std::endl;

    std::cout << "size of float: \t\t\t" << sizeof(float) << " bytes" << std::endl;
    std::cout << "size of double: \t\t" << sizeof(double) << " bytes" << std::endl;

    std::cout << "size of bool: \t\t\t" << sizeof(bool) << " bytes\n" << std::endl;

    typedef enum Piece {
        King, Queen, Rook, Pawn
    } PieceFirstTypeDef;

    typedef enum Piece PieceSecondTypeDef;
    
    PieceFirstTypeDef piece;
    PieceSecondTypeDef piece2;

    // Specifiy boolalpha format for boolean, otherwise it shows 1
    std::cout << "Are the two typedefs equivalent: " << std::boolalpha << (typeid(piece) == typeid(piece2)) << std::endl;

    std::cout << "size of enum: \t\t\t" << sizeof(PieceFirstTypeDef) << " bytes" << std::endl;

    std::cout << "size of enum*: \t\t\t" << sizeof(PieceFirstTypeDef*) << " bytes" << std::endl;
    std::cout << "size of int*: \t\t\t" << sizeof(int*) << " bytes" << std::endl;
    std::cout << "size of void*: \t\t\t" << sizeof(void*) << " bytes" << std::endl;
    std::cout << "size of long*: \t\t\t" << sizeof(long*) << " bytes\n" << std::endl;

    std::cout << "size of uint64_t: \t\t" << sizeof(uint64_t) << " bytes" << std::endl;
    std::cout << "size of uint32_t: \t\t" << sizeof(uint32_t) << " bytes" << std::endl;
    std::cout << "size of uint16_t: \t\t" << sizeof(uint16_t) << " bytes" << std::endl;
    std::cout << "size of uint8_t: \t\t" << sizeof(uint8_t) << " bytes\n" << std::endl;

    std::cout << "size of unsigned: \t\t" << sizeof(unsigned) << " bytes" << std::endl;
    std::cout << "size of unsigned long: \t\t" << sizeof(unsigned long) << " bytes" << std::endl;
    std::cout << "size of unsigned int: \t\t" << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "size of unsigned short: \t" << sizeof(unsigned short) << " bytes" << std::endl;
    std::cout << "size of unsigned char: \t\t" << sizeof(unsigned char) << " bytes" << std::endl;
    std::cout << "size of signed char: \t\t" << sizeof(signed char) << " bytes" << std::endl;

    return 0;
}