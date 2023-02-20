#include <iostream>
#include "test_namespace.h"

// pick one of the two name spaces
using namespace first_namespace;
// using namespace second_namespace;

int main(int argc, char** argv) {
    
    test(); // from picked namespace
    first_namespace::test(); // direct access
    second_namespace::test(); // direct access

    return 0;
}

// compile first with g++ -c test_namespace.cpp
// g++ master_test_namespace.cpp test_namespace.o
// run with ./a.out