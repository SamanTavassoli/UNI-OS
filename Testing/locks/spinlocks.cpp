/**
 * Note run w/ c++11 and above
 * Good tutorial on pthreads - https://www.bogotobogo.com/cplusplus/multithreading_pthread.php
*/

#include <iostream>
// #include <thread>
#include <pthread.h>
#include <atomic>

// std::atomic_flag // issues in c++11
// std::atomic_bool // c++'s implementation of monitors

class SpinLock
{
private:
    std::atomic_flag _lock; // c++'s implementation of data type that can access test_and_set

public:
    bool _disable;

    SpinLock() {
        _lock.clear();
        _disable = false;
    }

    void lock() {
        if (_disable) return;
        while (_lock.test_and_set());
    }

    void unlock() {
        if (_disable) return;
        _lock.clear();
    }
};

struct Resource
{
    int n;
};

struct ThreadArgs
{
    SpinLock *l;
    Resource *r;
};

void *t1(void *args)
{
    ThreadArgs *passed_args = static_cast<ThreadArgs *>(args);
    SpinLock *l = passed_args->l;
    Resource *r = passed_args->r;
    l->lock();
    
    for (int i = 0; i < 1; i++) {
        r->n +=5;
    }
    std::cout << "From t1: " << r->n << std::endl;
    l->unlock();
    pthread_exit(NULL);
}

void *t2(void *args)
{
    ThreadArgs *passed_args = static_cast<ThreadArgs *>(args);
    SpinLock *l = passed_args->l;
    Resource *r = passed_args->r;
    l->lock();
    for (int i = 0; i < 1; i++) {
        r->n *= 2;
    }
    std::cout << "From t2: " << r->n << std::endl;
    l->unlock();
    pthread_exit(NULL);
}

int main()
{

    SpinLock l;
    Resource r = {2};
    // l._disable = true;

    pthread_t first_thread;   
    pthread_t second_thread;

    ThreadArgs args = {&l, &r};

    // pthread_t in first, dk about second, thread function in third, arguments in fourth
    pthread_create(&first_thread, NULL, &t1, &args);
    pthread_create(&second_thread, NULL, &t2, &args);

    // for some reason I have to also get the exit status
    // pthread_join(first_thread, NULL);
    // pthread_join(second_thread, NULL);

    // this doesn't work if I define the exit status variables way above, but it works when I put it close by for some reason??
    int first_exit_status;
    int second_exit_status;
    pthread_join(first_thread, (void **)&first_exit_status);
    pthread_join(second_thread, (void **)&second_exit_status);
    std::cout << "exit statuses " << first_exit_status << " " << second_exit_status << std::endl;

    std::cout << "At the end: " << args.r->n << std::endl;

    return 0;
}