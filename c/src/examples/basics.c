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
    /*unsigned*/ char character = 'x'; // single quotes! unsigned by default
    /*unsigned*/ short shorty = 131;
    /*unsigned*/ int inty = -1612;
    /*unsigned*/ long longy = 10000;
    /*unsigned*/ long long extra_longy = 100000000;
    // literal notations
    char hexadecimal = 0x10;    // 16
    char octal       = 020;     // 16
    char binary      = 0b10000; // 16
    // suffixes L for "long" and U for "unsigned" can be added
    unsigned long long suffixes = 0ull;
    //// floating point numbers
    float floaty = 1.2f; // F suffix is optional, but good practice
    double doubly = 1.234;
    // exponential notation
    float exponential1 = 10.0e+3f; // "+" is optional
    float exponential2 = 10.0e-3f;
    //// constants
    const float PI = 3.14f;

    //// typedef
    // define type aliases at compile time
    typedef double my_number;
    my_number my_actual_number = 3.2;

    // accessing uninitialized variables is possible,
    // but causes undefined behavior
    int x;
    //printf("%d\n", x);

    ////// arithmetic and bitwise operators
    x = 0;
    //// arithmetic
    1 + 1; x += 1;
    1 - 1; x -= 1;
    1 * 1; x *= 1;
    1 / 1; x /= 1;
    1 % 1; x %= 1; // modulo
    // increment / decrement
    x++; ++x;
    x--; --x;
    //// bitwise
    assert((0b110 & 0b101) == 0b100); x &= 1; // AND
    assert((0b110 | 0b101) == 0b111); x |= 1; // OR
    assert((0b110 ^ 0b101) == 0b011); x ^= 1; // XOR
    assert(0b1100 << 1 == 0b11000); x <<= 1; // leftshift
    assert(0b1100 >> 1 ==   0b110); x >>= 1; // rightshift
    assert(~4 == -5); assert(~~3 == 3); // NOT (first complement)

    ////// pointers
    // a pointer has a memory address as its value.
    // it has an asterisk at the end of its type
    // (or the beginning of its name).
    // get the memory address of a variable with "&":
    int* int_pointer = &x;
    // "dereference" a pointer with another asterisk to get its value
    int int_pointer_value = *int_pointer;
    // a "null pointer" (pointing nowhere)
    char* null_pointer = NULL;
    // a "wild pointer" (pointing to garbage, not initialized)
    int* wild;
    // a "double pointer" (is possible!)
    int** int_pointer_pointer = &int_pointer;
    //// void pointers
    // - can hold memory address of any castable type
    // - can not be dereferenced
    // - can be used for generics
    void* void_pointer = &doubly;
    // can be casted and then dereferenced!
    double doubly_copy = *((double*) void_pointer);
    //// using const with pointers
    // allowed to change:                   value  pointer
          int* const const_ptr;          // yes    no
    const int*       ptr_to_const;       // no     yes
    const int* const const_ptr_to_const; // no     no

    ////// pointer arithmetic
    //// add/subtract integers
    // loop through array using pointer
    int array[] = {5, 6, 7, 8};
    size_t length = sizeof(array) / sizeof(int);
    int* pointer = &array[0];
    for (int i = 0; i < length; i++) {
      //printf("%d\n", *pointer);
      pointer++; // one unit = sizeof(int)
    }
    //// subtract pointers
    // 1 because &array[1] is the size of 1 int greater than &array[0]
    assert(&array[1] - &array[0] == 1);
    //// compare pointers
    assert(&array[1] > &array[0]);

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
    char manual_string1[] = {'S','t','r','i','n','g','\0'};
    // ascii value of \0 is 0
    char manual_string2[] = {'S','t','r','i','n','g',  0 };

    ////// _Generic
    // return different expressions based on the type of a value
    char type_name[] = _Generic(3.0,
        int: "int",
        float: "float",
        // ...
        default: "idk"
    );

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

    ////// volatile
    // variables marked as volatile are not optimized by
    // the compiler, meaning that their values aren't
    // cached but truly read again for every access.
    // useful for:
    // - variables whose value can be manipulated
    //   externally, e.g. by an I/O device
    // - variables who are accessed by multiple
    //   threads without other synchronization
    volatile int io_status = 0;
    // also used with pointers, meaning that the pointed-to value
    // is volatile, not the actual memory address the pointer holds
    volatile int* io_pointer = &io_status;
}