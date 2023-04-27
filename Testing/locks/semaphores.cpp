/**
 * Note run w/ c++11 and above
 * 
 * Useful references
 * - https://stackoverflow.com/questions/2763714/why-do-pthreads-condition-variable-functions-require-a-mutex
 * - https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_cond_wait.html
 * - https://stackoverflow.com/questions/16522858/understanding-of-pthread-cond-wait-and-pthread-cond-signal
 * 
 * Notes
 * - I tried to make this work my way, with my own sempahore & all, but c++ seems
 * to have it's own way of doing this, with the cond_wait and cond_signal, which I can just figure out
 * when I need to use it. For now I understand how this all works and time is better spent studying other things
*/

#include <iostream>
#include <pthread.h>
#include <atomic>
#include <list>

class SpinLock
{
private:
    std::atomic_flag _lock;

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

struct Semaphore
{
    int value;
    SpinLock *l; // have this as a pointer to a lock because for some reason it would't work
    std::list<pthread_t> list;
};

struct ThreadArgs
{
    Semaphore *s;
    Resource *r;
};


void wait(Semaphore *S) {
    S->l->lock();
    if (S->value <= 0) {
        S->list.push_back(some sort of self);
        // sleep this thread's execution
        S->l->unlock();
    } else {
        S->value--;
        S->l->unlock();
    }
}

void signal(Semaphore *S) {
    S->l->lock();
    if (S->value > 0) {
        pthread_t popped = S->list.back();
        S->list.pop_back();
        // wakeup a thread + continue own execution
    } else {
        S->value++;
    }
    S->l->unlock();
}

void *t1(void *args)
{
    ThreadArgs *passed_args = static_cast<ThreadArgs *>(args);
    Semaphore *s = passed_args->s;
    Resource *r = passed_args->r;
    wait(s);
    for (int i = 0; i < 1; i++) {
        r->n +=5;
    }
    std::cout << "From t1: " << r->n << std::endl;
    signal(s);
    pthread_exit(NULL);
}

void *t2(void *args)
{
    ThreadArgs *passed_args = static_cast<ThreadArgs *>(args);
    Semaphore *s = passed_args->s;
    Resource *r = passed_args->r;
    wait(s);
    for (int i = 0; i < 1; i++) {
        r->n *= 2;
    }
    std::cout << "From t2: " << r->n << std::endl;
    signal(s);
    pthread_exit(NULL);
}

int main()
{

    SpinLock l;
    std::list<pthread_t> list;
    Semaphore s = {1, &l, list}; // 1 for binary semaphore
    Resource r = {2};
    // l._disable = true;

    pthread_t first_thread;   
    pthread_t second_thread;

    ThreadArgs args = {&s, &r};

    pthread_create(&first_thread, NULL, &t1, &args);
    pthread_create(&second_thread, NULL, &t2, &args);

    pthread_join(first_thread, NULL);
    pthread_join(second_thread, NULL);

    std::cout << "At the end: " << args.r->n << std::endl;

    return 0;
}