#include <stdio.h>

int main() {
    printf("Hello world\n");
    return 0;
}


// To run
// First pre process -> gcc -E tutorial_1.c
// Second compile -> gcc -c tutorial_1.c -> creates object files
// Third create executable files -> gcc tutorial_2.c (this defaults to a.out exec file)
// Or name executable file -> gcc -o 'name' 'tutorial_1.c or tutorial_1.o based on if we have main function or not'
//  ex. gcc -o tutorial_1 tutorial_1.o -> this creates tutorial_1 exec file
// Fourth run ex. ./tutorial_1