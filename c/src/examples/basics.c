// for bool datatype (yes, really)
#include <stdbool.h>
// for size_t datatype  
#include <stddef.h>
// for assertions
#include <assert.h>

// global variables can be declared out here!
int global_variable = 2;

void example_basics () {
    ////// primitive datatypes
    //// boolean
    // constants "true" and "false" expand to 1 and 0
    bool boolean = true;
    bool illegal_bool = 2; // possible! but don't.
    //// integers
    // - adding "int" after something that is not "int" or
    //   "char" is possible, but doesn't change anything
    // - sizes are dependent on system and compiler
    //   and don't all have to be different
    /*unsigned*/ char character = 'x'; // single quotes!
    /*unsigned*/ short shorty = 131;
    /*unsigned*/ int inty = -1612;
    /*unsigned*/ long longy = 10000;
    /*unsigned*/ long long extra_longy = 100000000;
    //// floating point numbers
    float floaty = 1.2;
    double doubly = 1.234;

    // accessing uninitialized variables is possible,
    // but causes undefined behavior
    int x;
    //printf("%d\n", x);

    ////// pointers
    // a pointer has a memory address as its value.
    // it has an asterisk at the end of its type
    // (or the beginning of its name).
    // get the memory address of a variable with "&":
    int* int_pointer = &x;
    // "dereference" a pointer with another asterisk to get its value
    int int_pointer_value = *int_pointer;
    // a pointer pointing nowhere
    char* null_pointer = NULL;
    // a pointer pointing to another pointer (is possible!)
    int** int_pointer_pointer = &int_pointer;
    //// void pointers
    // - can hold memory address of any castable type
    // - can not be dereferenced
    // - can be used for generics
    void* void_pointer = &doubly;
    // can be casted and then dereferenced!
    double doubly_copy = *((double*) void_pointer);

    ////// arrays
    // declare but DON'T initialize an array with 10 elements.
    // each element has an unpredictable "garbage value" before
    // initialization, not a default like 0
    int weird_numbers[10];
    // declare and initialize array with 0's
    int zeros[10] = {};
    // declare and initialize array [1, 2, 0, 0, 0] 
    int some_numbers_some_zeros[5] = {1, 2};
    // declare and initialize array with 3 given elements
    int numbers[] = {1, 2, 3};
    // get array size with "sizeof" (number in bytes)
    size_t numbers_length = sizeof(numbers) / sizeof(numbers[0]);
    assert(numbers_length == 3);
    // array bounds are not checked automatically,
    // which means this is possible (and causes undefined behavior)
    int garbage = numbers[-1];
    //// "strings"
    // strings don't really exist, just pointers to char
    // arrays that are "null-terminated" (end with \0).
    // initializing like this ensures null-termination automatically:
    char* string_i_guess = "This isn't your typical string.";
    char second_string[] = "Same goes for this.";
    // this is also possible, but don't forget null termination!
    // without it, functions like printf() read the memory until
    // they randomly encounter another \0, which will probably
    // print some stuff you don't want.
    char manual_string[] = {'S','t','r','i','n','g','\0'};

    ////// storage classes / specifiers
    //// auto (initialized with garbage value)
    // same as without explicit storage class
    auto int automatic_sc;
    //// register (initialized with garbage value)
    // try to store in cpu register if possible for faster access times.
    // memory address can not be retreived!
    register int super_fast;
    //// static (initialized with 0)
    // will only be declared/initialized once during the whole
    // programs runtime! so something like this is possible:
    for (int i = 0; i < 10; i++) {
        static int only_initialized_once = 5;
        only_initialized_once++;
    } // => only_initialized_once = 15
    //// extern (initialized with 0)
    // tell the compiler to look for the value of this
    // variable somewhere else (see top of file!)
    // (not really necessary, also compiles without this)
    extern int global_variable;
    assert(global_variable == 2);
}