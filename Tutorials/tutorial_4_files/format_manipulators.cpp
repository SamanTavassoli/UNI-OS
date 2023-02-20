#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    // Note that since we are using std namespace, we don't use std::cout but just cout
    // Note that the spaces get printed correctly even with format manipulators (dec, oct, hex)
    cout << "some numbers in decimal: " << dec << 15 << " " << 12 << endl;
    cout << "in octal: " << oct << 15 << " " << 12 << endl;
    cout << "in hex: " << hex << 15 << " " << 12 << "\n";
    return 0;
}