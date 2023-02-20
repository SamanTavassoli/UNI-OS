///
// Examples retyped & modified from slides "Coding in C, Functions"
///
#include <stdio.h>

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

/*

*/

int
main()
{
    main1();
    main2();
    return 0;
}