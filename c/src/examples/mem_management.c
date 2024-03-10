// for malloc()
#include <stdlib.h>

void example_mem_management () {
    //// basics
    // data is stored on the stack by default
    int on_stack = 0;
    // to store data on the heap: dynamically allocate
    // memory for it (specifying the amount of bytes)
    int* on_heap = (int*) malloc(sizeof(int));
    *on_heap = 1;
    // dynamically allocated memory needs to be freed manually!
    free(on_heap);

    //// malloc (memory allocation)
    // dyn. allocate a single large block of (unitialized)
    // memory with the given size in bytes
    void* malloc_result = malloc(1);
    free(malloc_result);
}