#include <iostream>

using namespace std;

void change(int& ref) {
    ref++;
}

void change2(int& ref) {
    ref = 25;
}

int main(int argc, char** argv) {
    int x = 3; // declare normal int
    int& x_ref = x; // declare ref to int

    cout << "x is " << x << " and xRef is " << x_ref << endl;
    change(x_ref);
    cout << "x is " << x << " and xRef is " << x_ref << endl;
    change2(x_ref);
    cout << "x is " << x << " and xRef is " << x_ref << endl;

    cout << endl;

    int* int_ptr; // declare pointer
    int*& ptr_ref = int_ptr; // declare ref to pointer
    cout << "Note that the ref has the same value as the pointer: " << int_ptr << " " << ptr_ref << endl;
    ptr_ref = new int; // init pointer value (to 0) through ref
    cout << "Pointer points to new address and value of that address is 0: " << int_ptr << " " << ptr_ref << " " << *int_ptr << endl;
    *ptr_ref = 5; // set pointer via reference
    cout << "Dereference pointer reference and set pointer value: " << int_ptr << " " << ptr_ref << " " << *int_ptr << endl;
    *int_ptr = 6; // set pointer via pointer itself
    cout << "Dereference pointer and set pointer value: " << int_ptr << " " << ptr_ref << " " << *int_ptr << endl;

    cout << endl;

    int y = 3;
    int& y_ref = y;
    int* y_ptr = &y;
    int* y_ref_ptr = &y_ref;
    cout << "Taking addresss of ptr / ref gives the same address of y: " << y << " " << y_ref << " " << y_ptr << " " << y_ref_ptr << endl;

    return 0;
}