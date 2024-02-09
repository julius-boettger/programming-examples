// import standard i/o functionality like printf()
// using the "include" preprocessor directive,
// effectively copy-and-pasting the content
// of the referenced file here
#include <stdio.h>

// function signature declarations to tell the compiler
// to search for implementations of these functions in
// other files and use them here if they are called
void example_basics();
void example_control();
void example_functions();

// entry point of the program
// returns a "return code" as an integer, usually 0
int main () {
    printf("hello world!\n"); // doesn't add a new line itself!

    // call functions with example code from other files
    example_basics();
    example_control();
    example_functions();

    // indicate successful program execution and planned exit
    return 0;
}