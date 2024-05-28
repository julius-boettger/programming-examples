// for bool datatype (yes, really)
#include <stdbool.h>
// for size_t datatype  
#include <stddef.h>
// for assertions
#include <assert.h>
// for better int datatypes like uint8_t
#include <stdint.h>

// global variables can be declared out here.
// their lifetime is static by default (more on that later).
// "extern" and "const" will also be explained later.
extern const int global_variable = 2;

// don't worry about this, we just need it for later
int int_pow (int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

void example_basics () {
    ////// primitive datatypes
    //// boolean
    // constants "true" and "false" expand to 1 and 0
    bool boolean = true;
    bool illegal_bool = 2; // possible! but don't.
    //// integers
    // - "signed" by default
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
    // suffixes L for "long" and U for "unsigned" can be added
    unsigned long long suffixes = 0ull;
    //// floating point numbers
    float floaty = 1.2f; // F suffix is optional, but good practice
    double doubly = 1.234;
    long double extra_doubly = 1.23456;
    // exponential notation
    float exponential1 = 10.0e+3f; // "+" is optional
    float exponential2 = 10.0e-3f;

    //// other stuff
    // constants
    const float PI = 3.14f;
    // typedef: define type aliases at compile time
    typedef double my_number;
    my_number my_actual_number = 3.2;
    // you can declare/initialize multiple variables of the same type
    // but this is generally considered bad practice
    int x, y, z;
    int a = 3, b = 2, c = 1;
    // assigning the same value to multiple variables is possible like this
    // because x = y first assigns y to x and then returns x, which is chainable
    x = y = 100;
    assert(x == 100 && y == 100);
    // you can evaluate multiple expressions using the comma operator,
    // which returns the last operand. bad practice!
    int comma_evaluated = ("hello", true, 2+2, 10);
    assert(comma_evaluated == 10);
    // nested block are possible
    {
        // only accessible in this block/scope!
        int some_variable;
    }
    // accessing uninitialized variables is possible,
    // but causes undefined behavior
    //printf("%d\n", z);

    ////// arithmetic and bitwise operators
    x = 0;
    //// arithmetic
    1 + 1; x += 1;
    1 - 1; x -= 1;
    1 * 1; x *= 1;
    1 / 1; x /= 1;
    1 % 1; x %= 1; // modulo
    // increment / decrement
    // good practice: prefer prefix versions wherever possible,
    // they are less likely to cause unwanted surprises
    // and sometimes even offer performance benefits
    x++; ++x;
    x--; --x;
    //// bitwise
    // WARNING: the C language standard does not support
    // binary notation with 0b prefix, but the GCC compiler does.
    // this is called a "compiler extension"
    // and should be avoided for combatability.
    assert((0b110 & 0b101) == 0b100); x &= 1; // AND
    assert((0b110 | 0b101) == 0b111); x |= 1; // OR
    assert((0b110 ^ 0b101) == 0b011); x ^= 1; // XOR
    assert(~4 == -5); assert(~~3 == 3); // NOT (first complement)
    // leftshift: fill with 0, LSB first
    assert(0b1100 << 1 == 0b11000); x <<= 1;
    // interpretation: multiplication with power of two
    x = 3; y = 2; assert(x << y == x * int_pow(2, y));
    // rightshift: fill with MSB (here: 0), MSB first
    assert(0b1100 >> 1 == 0b110); x >>= 1;
    // interpretation: integer division with power of two
    x = 32; y = 3; assert(x >> y == x / int_pow(2, y));

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
    //// restrict
    // promise the compiler that a pointer is the only way to
    // access the object it points to in this scope (to enable
    // some optimizations). accessing/modifying the pointed-to
    // object directly is still allowed though!
    int may_be_pointed_to = 0;
    int *restrict restricted = &may_be_pointed_to;

    ////// pointer arithmetic
    //// add/subtract integers
    // loop through array using pointer
    int array[] = {5, 6, 7, 8};
    size_t length = sizeof(array) / sizeof(int);
    int* pointer = &array[0];
    for (unsigned int i = 0; i < length; ++i) {
      //printf("%d\n", *pointer);
      ++pointer; // one unit = sizeof(int)
    }
    //// subtract pointers
    // 1 because &array[1] is the size of 1 int greater than &array[0]
    assert(&array[1] - &array[0] == 1);
    //// compare pointers
    assert(&array[1] > &array[0]);

    ////// stdint.h
    // stdint.h contains new data types for integers
    // which have fixed, platform-independent sizes.
    // all the following types are available in sizes
    // 8, 16, 32 and 64 (bit).
    // the prefix "u" for "unsigned" is also available.
    int8_t int8;
    // largest type the system supports
    intmax_t intmax;
    // smallest type the system supports that is at least 8 bit
    int_least8_t int_least8;
    // fastest type the system supports that is at least 8 bit
    // (might not be smallest)
    int_fast8_t int_fast8;
    // useful for performing bitwise operations on a pointer
    // by treating its contained memory address like an integer,
    // e.g. for pointer comparison
    uintptr_t intptr = (uintptr_t) &hexadecimal;

    ////// arrays
    // declare but DON'T initialize an array with 10 elements.
    // each element has an unpredictable "garbage value" before
    // initialization, not a default like 0
    int weird_numbers[10];
    // declare and initialize array with 0's:
    // - "{0}" => explicitly set first element to 0
    // - implicitly set all remaining elements to 0
    int zeros[10] = {0};
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
    // programs runtime! this is also called "static lifetime".
    // so something like this is possible:
    for (int i = 0; i < 10; ++i) {
        static int only_initialized_once = 5;
        ++only_initialized_once;
    } // => only_initialized_once = 15
    // global or static variables reside in the
    // "initialized data segment", a special segment of
    // the processes virtual memory for global variables.
    //// extern (initialized with 0)
    // has two meanings, based on context:
    // 1.: allow a global variable to be accessed 
    //     from other files (see top of this file)
    // 2.: tell the compiler to look for the value of this
    //     variable somewhere else, could even be in another file
    //     (here: top of this file, similar to function prototypes)
    extern const int global_variable;
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