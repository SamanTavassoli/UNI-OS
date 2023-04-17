/**
 * Goal of this exploration:
 * - Fork processes
 * - Run separate things on each process
 * - Merge processes
 * References:
 * https://man7.org/linux/man-pages/man2/fork.2.html
*/
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

void print_info(string name, pid_t pid) {
    cout << name << endl;
    cout << "child pid from fork:\t\t" << pid << endl;
    cout << "self pid from getpid():\t\t" << getpid() << endl;
    cout << "parent pid from getppid():\t" << getppid() << endl << endl;
}

int main() {
    print_info("Initial Process- ignore child pid", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        cout << "ERROR: Process failed" << endl;
        return 1;
    } else if (pid == 0) {
        print_info("Process 1 - child", pid);
    } else {
        print_info("Process 2 - parent", pid);
    }

    return 0; // Note that both processes get to this point and their execution stops
}