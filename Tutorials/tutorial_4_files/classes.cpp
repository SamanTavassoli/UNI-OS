#include <iostream>
#include "classes.h"


someNamespace::TestClass::TestClass() {
   somePrivateMember = true; 
}

someNamespace::TestClass::~TestClass() {
    // I could return something from destructor if I wanted to
}

std::string someNamespace::TestClass::someFunctionReturningString() {
    return "Hey";
}

// could start using a namespace here if I wanted to
using namespace someNamespace;

int main(int argc, char** argv) {
    
    TestClass instance1; // on stack
    TestClass* instance2; // on heap

    // Note how the functions are called
    std::cout << instance1.someFunctionReturningString() << std::endl;
    std::cout << instance2->someFunctionReturningString() << std::endl;
    // If the pointer is derefenced we can just call normally
    std::cout << (*instance2).someFunctionReturningString() << std::endl;
    
    return 0;
}
