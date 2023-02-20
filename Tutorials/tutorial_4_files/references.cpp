#include <iostream>

using namespace std;

void addOne(int i) {
    i++;
}

void REFaddOne(int& i) {
    i++;
}

int main(int argc, char** argv) {
    int myInt = 123;

    addOne(myInt);
    cout << "addOne " << myInt << endl;

    REFaddOne(myInt);
    cout << "REFAddOne " << myInt << endl;
    
    return 0;
}