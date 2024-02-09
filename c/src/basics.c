// for bool datatype (yes, really)
#include <stdbool.h>
// for size_t datatype  
#include <stddef.h>

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
}