// for malloc()
#include <stdlib.h>

void example_mem_management () {
    // data is stored on the stack by default
    int on_stack = 0;
    // to store data on the heap: dynamically allocate
    // memory for it with malloc and the amount of bytes
    int* on_heap = (int*) malloc(sizeof(int));
    *on_heap = 1;
    // dynamically allocated memory needs to be freed manually!
    free(on_heap);
}