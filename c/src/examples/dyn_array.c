// C has no built-in data structures (besides the simple array),
// so implementing them yourself is necessary.
// below is a simple dynamic array, which can also be used as a stack.

#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdio.h>

typedef struct {
    size_t size;
    int* data;
} DynArray;

static DynArray initialize_dyn_array () {
    DynArray result = { 0, NULL };
    return result;
}

static void destroy_dyn_array (DynArray* dyn_array) {
    if (dyn_array->data != NULL) {
        free(dyn_array->data);
        dyn_array->data = NULL;
    }
    dyn_array->size = 0;
}

static size_t size_dyn_array (DynArray* dyn_array) {
    return dyn_array->size;
}

static bool is_empty_dyn_array (DynArray* dyn_array) {
    return size_dyn_array(dyn_array) == 0;
}

static int get_element_dyn_array (DynArray* dyn_array, size_t index) {
    return dyn_array->data[index];
}

static void set_element_dyn_array (DynArray* dyn_array, size_t index, int value) {
    dyn_array->data[index] = value;
}

static void push_dyn_array (DynArray* dyn_array, int element) {
    if (is_empty_dyn_array(dyn_array)) {
        dyn_array->data = malloc(sizeof(int));
    } else {
        // allocate memory for one more element
        dyn_array->data = realloc(dyn_array->data, (size_dyn_array(dyn_array) + 1) * sizeof(int));
    }
    set_element_dyn_array(dyn_array, size_dyn_array(dyn_array), element);
    dyn_array->size++;
}

static int pop_dyn_array (DynArray* dyn_array) {
    if (is_empty_dyn_array(dyn_array)) {
        return INT_MIN;
    } 
    size_t size = size_dyn_array(dyn_array);
    int result = get_element_dyn_array(dyn_array, size - 1);
    if (size == 1) {
        free(dyn_array->data);
        dyn_array->data = NULL;
    } else {
        dyn_array->data = realloc(dyn_array->data, (size - 1) * sizeof(int));
    }
    dyn_array->size--;
    return result;
}

static void print_dyn_array (DynArray* dyn_array) {
    size_t size = size_dyn_array(dyn_array);
    printf("size: %ld, data: [", size);
    if (size == 0) {
        printf("]\n");
        return;
    }
    for (unsigned int i = 0; i < size - 1; i++) {
        printf("%d, ", get_element_dyn_array(dyn_array, i));
    }
    printf("%d]\n", get_element_dyn_array(dyn_array, size - 1));
}

void example_dyn_array () {
    DynArray dyn_array = initialize_dyn_array();
    assert(size_dyn_array(&dyn_array) == 0);
    //print_dyn_array(&dyn_array);
    
    // push some elements
    //printf("pushing...\n");
    push_dyn_array(&dyn_array, 1);
    push_dyn_array(&dyn_array, 2);
    push_dyn_array(&dyn_array, 3);
    assert(size_dyn_array(&dyn_array) == 3);
    assert(get_element_dyn_array(&dyn_array, 0) == 1);
    assert(get_element_dyn_array(&dyn_array, 1) == 2);
    assert(get_element_dyn_array(&dyn_array, 2) == 3);
    //print_dyn_array(&dyn_array);

    // pop an element
    int popped_element = pop_dyn_array(&dyn_array);
    //printf("popped [%d]\n", popped_element);
    assert(size_dyn_array(&dyn_array) == 2);
    assert(get_element_dyn_array(&dyn_array, 0) == 1);
    assert(get_element_dyn_array(&dyn_array, 1) == 2);
    //print_dyn_array(&dyn_array);

    // pop until empty
    popped_element = pop_dyn_array(&dyn_array);
    //printf("popped [%d]\n", popped_element);
    popped_element = pop_dyn_array(&dyn_array);
    //printf("popped [%d]\n", popped_element);
    assert(size_dyn_array(&dyn_array) == 0);
    //print_dyn_array(&dyn_array);

    // don't forget to free the memory!
    destroy_dyn_array(&dyn_array);
}