/**
 * Figuring out cw1 and pointer/object manipulation
*/

#include <iostream>

using namespace std;

struct TestStruct
{
    TestStruct *next;
    int value;
};

void print_struct(TestStruct *struct_) {
    cout << struct_ << " " << struct_->value << " " << struct_->next << endl;
}

void change_structs(TestStruct *test) {
    cout << endl;
    print_struct(test);
    test->value = 4;
    print_struct(test);
    TestStruct *test2 = test;
    print_struct(test2);
    test2 = test->next;
    print_struct(test);
    print_struct(test2);
}

int main(int argc, char** argv) {
    // any testing here

    int N = 10;
    TestStruct *tests[N];
    for (int i = 0; i < N; i++) {
        TestStruct *new_struct = new TestStruct();
        new_struct->value = i;
        tests[i] = new_struct;
        new_struct->next = tests[0];
        print_struct(new_struct);
    }
    change_structs(tests[3]);


    return 0;
}