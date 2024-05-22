/*

some notes

- this project with C++ examples assumes you know C and aims to only
  show the difference to C, which is not everything C++ has to offer
- as of C++23, the language standard does not contain C's restrict
  keyword, although many compilers have implemented it
- storage class specifiers "auto" and "register" are deprecated
  (since C++10 and C++17)

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
    classes::run_examples();
    control::run_examples();
    enums::run_examples();
    functions::run_examples();
    namespaces::run_examples();
    op_overloading::run_examples();
    optionals::run_examples();
    smart_ptrs::run_examples();
    strings::run_examples();
    structs::run_examples();

    return 0;
}