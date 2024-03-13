// use Check for unit testing (external dependency)
// but only if it's available on the host system!
#if __has_include(<check.h>)
#include <check.h>

void example_unit_test () {
    
}

// if Check is not available on the host system
#else
#include <stdio.h>
void example_unit_test () {
    printf("install Check to run unit test examples!");
}
#endif