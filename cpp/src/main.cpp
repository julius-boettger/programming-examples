/*

some notes

- this project with C++ examples assumes you know C and aims to only
  show the difference to C, which is not everything C++ has to offer

*/

#include <iostream>

int main() {
    // print to console:
    // uses "cout" (character output stream) of the "std" (standard) namespace
    // "<<" is the leftshift operator (like in C) that has been overloaded for streams
    // to behave differently, resulting in the so-called "insertion operator".
    std::cout << "Hello World :)";

    return 0;
}