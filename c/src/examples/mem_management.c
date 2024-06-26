#include <assert.h>
// for memory management functions
#include <stdlib.h>

void example_mem_management () {
    //// basics
    // data is stored on the stack by default
    int on_stack = 0;
    // to store data on the heap: dynamically allocate
    // memory for it (specifying the amount of bytes)
    int* on_heap = (int*) malloc(sizeof(int));
    // malloc/calloc/realloc can return NULL if allocation failed
    if (on_heap == NULL) {
        // do something
    }
    *on_heap = 1;
    // dynamically allocated memory needs to be freed manually!
    free(on_heap);

    //// malloc (memory allocation)
    // dyn. allocate a single large block of (unitialized)
    // memory with the given size in bytes
    int* malloc_int = malloc(sizeof(int));
    *malloc_int = 3;
    free(malloc_int);

    //// calloc (clear allocation)
    // like malloc, but allocates multiple blocks of given size
    // and initializes them with a default value (usually 0).
    // useful for when you want to initialize your data with 0 anyway.
    unsigned int calloc_len = 5;
    int* calloc_array = (int*) calloc(calloc_len, sizeof(int));
    calloc_array[3] = 12;
    assert(calloc_array[0] ==  0);
    assert(calloc_array[1] ==  0);
    assert(calloc_array[2] ==  0);
    assert(calloc_array[3] == 12);
    assert(calloc_array[4] ==  0);
    free(calloc_array);

    //// realloc (re-allocation)
    // change the size of previously dyn. allocated memory, preserving
    // the present value and possibly allocating new (uninitialized) blocks
    int* realloc_array = (int*) malloc(2 * sizeof(int));
    realloc_array[0] = 1;
    realloc_array[1] = 2;
    assert(realloc_array[0] == 1);
    assert(realloc_array[1] == 2);
    // allocate more memory for new element
    realloc_array = (int*) realloc(realloc_array, 3 * sizeof(int));
    // assign value to new element
    realloc_array[2] = 3;
    assert(realloc_array[0] == 1);
    assert(realloc_array[1] == 2);
    assert(realloc_array[2] == 3);
    // free/deallocate memory for last element
    realloc_array = (int*) realloc(realloc_array, 2 * sizeof(int));
    assert(realloc_array[0] == 1);
    assert(realloc_array[1] == 2);
}
