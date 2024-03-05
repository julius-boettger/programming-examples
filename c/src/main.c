/*

some notes about c

- c has no built-in exception handling. in places where
  other languages would throw runtime errors, c allows
  "undefined behavior", which often just means returning
  an unpredictable value when trying to do something illegal.

*/

// import standard i/o functionality like printf()
// using the "include" preprocessor directive,
// effectively copy-and-pasting the content
// of the referenced file here
#include <stdio.h>

// function signature declarations to tell the compiler
// to search for implementations of these functions in
// other files and use them here if they are called
void example_basics();
void example_unions();
void example_structs();
void example_control();
void example_functions();

// entry point of the program
// returns a "return code" as an integer, usually 0
int main () {
// can also take arguments
//int main(int argc, char* argv[]) {

    printf("hello world!\n"); // doesn't add a new line itself!

    // call functions with example code from other files
    example_basics();
    example_unions();
    example_structs();
    example_control();
    example_functions();

    // indicate successful program execution and planned exit
    return 0;
}