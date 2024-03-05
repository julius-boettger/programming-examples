/*

- the preprocessor processes code before compilation.
- preprocessor directives start with a "#".

*/

//// file inclusion
// copy-and-paste the contents of the mentioned file here
// the "" signify a relative file location to the current source file
#include "../examples.h"
// include twice to see that that's no problem :)
// look in examples.h to find out more!
#include "../examples.h"
// include files located in the system/default directory with <>
#include <stdio.h>
#include <assert.h>

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
        printf("How did we get here?\n");
    #endif
}