// include bool datatype (yes, really)
#include <stdbool.h>

void example_basics () {
    ////// datatypes
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
}