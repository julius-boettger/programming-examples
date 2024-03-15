/*

some notes

- this project with C++ examples assumes you know C and aims to only
  show the difference to C, which is not everything C++ has to offer

*/

#include "examples.h"
// for std::cout. notice the missing ".h"!
// <iostream.h> also exists, but doesn't use the std namespace.
// <iostream> is also a header file, but without a
// file extension and using the std namespace.
#include <iostream>

int main() {
    // print to console:
    // uses "cout" (character output stream) of the "std" (standard) namespace
    // "<<" is the leftshift operator (like in C) that has been overloaded for streams
    // to behave differently, resulting in the so-called "insertion operator".
    std::cout << "Hello World :)";

    basics::run_examples();

    return 0;
}