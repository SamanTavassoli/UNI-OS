#include <iostream>
#include <typeinfo>

int main(int argc, char** argv) {

    // Using \t to add tabs to line up results
    std::cout << "size of char: \t\t\t" << sizeof(char) << " bytes" << std::endl;
    std::cout << "size of short [int]: \t\t" << sizeof(short) << " bytes" << std::endl;
    std::cout << "size of int: \t\t\t" << sizeof(int) << " bytes" << std::endl;
    std::cout << "size of long [int]: \t\t" << sizeof(long) << " bytes" << std::endl;
    std::cout << "size of long long [int]: \t" << sizeof(long long) << " bytes" << std::endl;

    std::cout << "size of float: \t\t\t" << sizeof(float) << " bytes" << std::endl;
    std::cout << "size of double: \t\t" << sizeof(double) << " bytes" << std::endl;

    std::cout << "size of bool: \t\t\t" << sizeof(bool) << " bytes" << std::endl;

    typedef enum Piece {
        King, Queen, Rook, Pawn
    } PieceFirstTypeDef;

    typedef enum Piece PieceSecondTypeDef;
    
    PieceFirstTypeDef piece;
    PieceSecondTypeDef piece2;

    // Specifiy boolalpha format for boolean, otherwise it shows 1
    std::cout << "Are the two typedefs equivalent: " << std::boolalpha << (typeid(piece) == typeid(piece2)) << std::endl;

    return 0;
}