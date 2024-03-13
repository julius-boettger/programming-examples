// include pthread.h ("posix thread"), which is not part of
// the standard library, but is usually supplied by the compiler
#include <pthread.h>
// similar story for this include.
// provides sleep()
#include <unistd.h>

// functions that are supposed to be run by other threads
// typically have this signature. they return void* and
// also accept a single void* argument.
static void* will_be_run_as_a_thread (void* arg) {
    // just wait a little bit :)
    sleep(0.1);
    return NULL;
}

void example_concurrency () {
    // most of the pthread_[...] functions used here return
    // an integer which 

    //// create thread. this has 4 arguments:
    // 1. pointer to pthread_t to write thread id to
    // 2. pointer to pthread_attr_t (attributes object)
    // 3. pointer to function that the thread will execute
    //    (usually returns void* and has one void* argument)
    // 4. void* argument that will be passed
    //    to referenced function on start
    pthread_t thread1; 
    pthread_create(&thread1, NULL, will_be_run_as_a_thread, NULL); 

    //// attributes
    pthread_attr_t attributes;
    pthread_attr_init(&attributes);
    // make thread joinable (default)
    pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_JOINABLE);
    // tell scheduler to use Round Robin (SCHED_OTHER is default)
    pthread_attr_setschedpolicy(&attributes, SCHED_RR);
    // and others!

    // run a new thread with the given attributes
    pthread_t thread2;
    pthread_create(&thread2, &attributes, will_be_run_as_a_thread, NULL); 
    // wait for both created threads to terminate in this thread, saving their return values
    void* thread1_return_value;
    void* thread2_return_value;
    pthread_join(thread1, &thread1_return_value); 
    pthread_join(thread2, &thread2_return_value); 
    // don't forget to destroy your attributes!
    pthread_attr_destroy(&attributes);
}