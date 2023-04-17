/**
 * Testing that shared memory with boost works with multiple processes
*/

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <sys/wait.h>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::interprocess;

int main(int argc, char *argv[]) {

    string shm_name = "shared_memory";
    size_t shm_size = 10000; // Bytes
 
    // note that create_only lets us check that it was successfully removed last time
    shared_memory_object shm_obj(create_only, shm_name.c_str(), read_write);
    shm_obj.truncate(shm_size);

    pid_t pid = fork();

    if (pid < 0) {
        cout << "ERROR: Process failed" << endl;
        return 1;
    } else if (pid == 0) { // child
        mapped_region region(shm_obj, read_write, 0, shm_size);
        string message = "This is a message created in the child after forking, pid of child: " + to_string(getpid());
        memcpy(region.get_address(), message.c_str(), message.size());
        // exit(0);
    } else {
        int status; // to hold exit status of child
        pid_t w = wait(&status); // this by default waits until child suspends execution
        if (w == -1) { // standard error handling on failure
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
        mapped_region region(shm_obj, read_only, 0, shm_size);
        char buffer[512];
        memcpy(&buffer, region.get_address(), 512);
        cout << buffer << endl;
        
        if (!shared_memory_object::remove(shm_name.c_str())) {
            cout << "ERROR: Couldn't remove shared memory object" << endl;
        }

        // TODO: Wierd that I can still access and retreive the message but investigation left for later
        char buffer2[512];
        memcpy(&buffer2, region.get_address(), 512);
        cout << buffer2 << endl;
    }


    return 0;
}