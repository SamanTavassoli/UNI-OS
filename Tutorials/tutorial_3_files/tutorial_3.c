///
// Examples retyped & modified from slides "Coding in C, Functions"
///
#include <stdio.h>
#include <string.h>

/*
    Declaring and calling a function
    Start slide 4

    Computes the square of a number
*/
static int square(int num) {
    int result = num * num;
    return result;
}

int
main1()
{
    int a = 3;
    int b;
    b = square(a); //call
    // b is now 9
    return 0;
}


/*
    Swap example
    With / without pointers
    Start slide 6, 7, 

    Doesn't work as you'd expect
    Remember: arguments passed by value
*/
void swap (int x, int y) {
    int temp;
    temp = x;

    x = y;
    y = temp;
}

int
main2()
{
    // somewhere else in the code
    int a = 1;
    int b = 2;

    printf("&x %p &y %p\n", &a, &b);

    swap(a, b);
    // swap(&a, &b);

    printf("a %d b %d\n", a, b);
    return 0;
    // a is 1,  b is 2
}

void count(char c, int *counts) {
    if (c == 'a') counts[0]++;
    if (c == 'b') counts[1]++;
    if (c == 'e') counts[2]++;
}

int
main3()
{
    // end of slides C4 exercise
    char str[] = "The overwhelming majority of program bugs and computer crashes stem from problems of memory access, allocation, or deallocation. Such memory-related errors are also notoriously difficult to debug.";
    
    int counts[] = {0, 0, 0};
    for (int i = 0; i < strlen(str); i++) {
        count(str[i], counts); // note that arrays are passed in by pointer of first element so no need to get reference
    }
    printf("a count: %d, b count: %d, e count: %d\n", counts[0], counts[1], counts[2]);

    return 0;
}

/*

*/

int
main()
{
    main1();
    main2();
    main3();
    return 0;
}