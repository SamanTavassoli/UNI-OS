#include <iostream>
#include <cstring>
#include <string>

int main(int argc, char** argv) {
    
    // C style strings
    char str1[] = "C Style";
    char str2[] = "Hello World";
    char c_style[20];
    strcat(c_style, str1);
    strcat(c_style, " ");
    strcat(c_style, str2);
    std::cout << c_style << std::endl;

    // C++ style strings
    std::string str3 = "C++ style";
    std::string str4 = "Hello World";
    std::string cpp_style = str3 + " " + str4;
    std::cout << cpp_style << std::endl;

    // Nonstandard strings (exist but not covered here)

    return 0;
}