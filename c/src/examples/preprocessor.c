/*

- the preprocessor processes code before compilation.
- preprocessor directives start with a "#".

*/

//// file inclusion
// copy-and-paste the contents of the mentioned file here
// the "" signify a relative file location to the current source file
#include "../include/examples.h"
// include twice to see that that's no problem :)
// look in examples.h to find out more!
#include "../include/examples.h"
// include files located in the system/default directory with <>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//// #pragma directive
// enable/disable compiler-specific features,
// e.g. run a function at program startup before main()
static void startup_func() { /* before main()! */ }
#pragma startup startup_func

void example_preprocessor() {
    //// macros
    // define a macro
    #define CONSTANT 5
    // CONSTANT will be replaced with its value before compilation
    assert(CONSTANT == 5);
    // "undefine" a macro (delete it)
    #undef CONSTANT
    // can also define simple functions with arguments
    #define ADD(a, b) (a + b)
    assert(ADD(1, 4) == 5);
    // "#" is the "stringizing operator"
    #define VAR_NAME(var) #var
    int my_var = 4;
    assert(strcmp("my_var", VAR_NAME(my_var)) == 0); // compare strings
    // "##" is the "token-pasting operator"
    #define concat(a, b) a##b
    assert(concat(1, 2) == 12);
    // macro definition can be multiple lines long with backslashes
    #define THREE_PRINTS \
        printf("1\n"); \
        printf("2\n"); \
        printf("3\n");
    // use the macro
    //THREE_PRINTS

    //// conditional compilation
    // only compile if macro is defined
    #ifdef CONSTANT
        printf("I know what CONSTANT is!\n");
    #else
        // do nothing :)
    #endif
    // only compile if macro is NOT defined
    #ifndef SOME_MACRO
        // do nothing :)
    #endif
    // only compile if a static expression is true
    #if 3 == 3
        // thats good :)
    #elif 3 == 2
        printf("This... feels wrong\n");
    #else
        // show error message during preprocessing
        #error how did we get here?
    #endif

    //// branch prediction macros
    // these macros are from the linux kernel! they use __builtin_expect
    // as a compiler hint for possible optimization if a condition
    // is known to be true/false more than the other.
    #define   likely(x) __builtin_expect(!!(x),  true)
    #define unlikely(x) __builtin_expect(!!(x), false) 
    // use like this when you know if a condition is likely to be true/false
    if (likely(0 == 0)) {
        // something likely
    } else {
        // something unlikely
    }
}