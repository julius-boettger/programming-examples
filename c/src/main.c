/*

some notes

- see instructions on how to build/run in meson.build
- c has no built-in exception handling. in places where
  other languages would throw runtime errors, c allows
  "undefined behavior", which often just means returning
  an unpredictable value when trying to do something illegal.

*/

// see what this does in preprocessor.c!
#include "include/examples.h"
#include <stdio.h>

// entry point of the program
// returns a "return code" as an integer, usually 0
int main () {
// can also take arguments
//int main(int argc, char* argv[]) {

    printf("hello world!\n"); // doesn't add a new line itself!

    // call functions with example code from other files
    example_enums();
    example_basics();
    example_unions();
    example_structs();
    example_control();
    example_functions();
    example_preprocessor();
    example_mem_management();

    // indicate successful program execution and planned exit
    return 0;
}