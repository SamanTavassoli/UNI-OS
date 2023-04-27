/**
 * Monitors in c++
 * Can use std::atomic_bool or other objects
 * Can use pthread_mutex & pthread_cond_wait & pthread_cond_signal to implement
 * Not gonna make it for now, but basic implementation would be a class that has two acess methods,
 * and ensures one thread running at a time and all the other stuff a monitor requires
*/