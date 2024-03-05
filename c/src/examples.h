/*

- this is a "header file" (.h). it is used for
  function prototypes, structs, enums, constants, global variables, ...
  to avoid redundancy when sharing code between source files (.c).
- its contents are typically wrapped with conditional
  preprocessor directives to avoid problems when
  including the same header file multiple times.

*/

// "if not defined" with name of this file
#ifndef examples 
#define examples

// function prototypes to tell the compiler to
// search for definitions of these functions in
// other files and use them here if they are called.
// see functions.c for more.
void example_enums();
void example_basics();
void example_unions();
void example_structs();
void example_control();
void example_functions();

#endif