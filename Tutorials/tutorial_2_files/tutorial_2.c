#include <stdio.h>

int
main()
{
    // Exercise at the end of the slides
    char s[1024] = "The overwhelming majority of program bugs and computer crashes stem from problems of memory access, allocation, or deallocation. Such memory-related errors are also notoriously difficult to debug.";
    int count_a = 0, count_b = 0, count_e = 0, i;
    
    for (i = 0; i < 1024; i++) {
        if (s[i] == 'a')
            count_a++;
        else if (s[i] == 'b')
            count_b++;
        else if (s[i] == 'e')
            count_e++;
    }

    printf("a %d, b %d, e %d\n", count_a, count_b, count_e);
    return 0;
}