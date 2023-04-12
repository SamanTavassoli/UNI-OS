/**
 * Testing the time it takes to communicate between processes with:
 * 1. Shared Memory
 * 2. Message Passing
 * 3. Signals
 * Haven't gotten so far yet because I'm confusing myself with c and c++, do this when I have time
*/

#include <iostream>
#include <string>

#include <chrono>
#include <thread>

#include <unistd.h>
#include <inttypes.h>

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> /* For O_* constants */
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

using namespace std;

class Process {
private:

protected:
    int _fd; /* shared memory file descriptor */
    char *_ptr; /* pointer to shared memory object */
    
public:

    Process()
    : _SIZE(4096),
    _NAME("/SHM_OS")
    {

    }

    const int _SIZE; /* the size (bytes) of shared memory object */
    const char *_NAME; /* name of shared memory object */
    
};

class Client : private Process {
private:
    
public:
    void send_message(char message[]) {
        /* create the shared memory object */
        _fd = shm_open(_NAME, O_CREAT | O_RDWR, 0666);
        /* configure the size of the shared memory object */
        ftruncate(_fd, _SIZE);
        /* memory map the shared memory object */
        _ptr = (char *) mmap(0, _SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
        /* write to the shared memory object */
        sprintf(_ptr, "%s", message);
        // fwrite(&now, sizeof(now), 1, ptr);
    }
};

class Server : private Process {
private:
public:
    ~Server() {
        /* remove the shared memory object */
        shm_unlink(_NAME);
    }
    void receive_message() {
        _fd = shm_open(_NAME, O_CREAT | O_RDWR, 0666);
        ftruncate(_fd, _SIZE);
        _ptr = (char *) mmap(0, _SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
        printf("%s", (char *)_ptr);
    }

};

int main(int argc, char** argv) {
    char message[] = "Hello World\n";

    int pid = fork(); /* start new process for server */
    if (pid < 0) {
        cout << "Fork failed" << endl;
        return 1;
    }
    if (pid == 0) { /* Child process */
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Server *server = new Server();
        server->receive_message();
    } else { /* Parent process */
        Client *client = new Client();
        client->send_message(message);
    }

    return 0;
}