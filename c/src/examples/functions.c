#include <assert.h>

// the simplest function (globally accessible by default). needs
// to have a unique identifier to not conflict with functions
// defined elsewhere! (something like namespaces doesn't exist)
void do_nothing () {}
// can also be written like this,
// with "void" standing for "no arguments"
void do_nothing_fancy (void) {}
// static functions are not globally accessible,
// but only accessible in the file they were declared in
static void only_in_this_file () {}

// a function with an argument (pass-by-value)
int get_double (int x) {
    return x * 2;
}
// the same function, but pass-by-pointer:
// essentially pass-by-value for pointers, which
// feels like pass-by-reference, but it isn't
void double_in_place (int* x) {
    *x *= 2;
}

// function overloading like this is not possible!
//void double_in_place (float* x) {
//    *x *= 2;
//}

// for later examples
int sum (int a, int b) {
    return a + b;
}
int* get_number () {
    static int hidden_number = 12;
    return &hidden_number;
}

// take a function with a signature like sum's as the first argument
// see more on function pointers below
int sum_wrapper (int (*sum_)(int, int), int a, int b) {
    return sum_(a, b);
}
// function pointer types can be shortened in function signatures:
int sum_wrapper_2 (int sum_(int, int), int a, int b) {
    return sum_(a, b);
}
// can be made generic using void pointers
void* useless_wrapper (void* fn()) {
    return fn();
}

// to call a function that was not defined in
// the current source file it SHOULD be declared
// (without being defined, like below). this is also
// called a "function prototype" or "forward declaration":
void defined_elsewhere ();
// the linker will then search for a definition
// somewhere else, and could find one like this:
void defined_elsewhere () {
    // do something
}

// order of functions in code is important!
// the following only works because a declaration
// for defined_elsewhere() was provided before the
// definition of this function.
void call_earlier_defined () {
    defined_elsewhere();
}

void example_functions () {
    // call the funtions declared above
    do_nothing();

    assert(get_double(2) == 4);

    int x = 3;
    double_in_place(&x);
    assert(x == 6);

    //// function pointers
    // the parentheses are necessary!
    int (*sum_pointer)(int, int) = &sum; // "&" is optional
    // can be called like regular functions
    assert(sum_pointer(3, 4) == 7);
    // reference sum() without "&"
    assert(sum_wrapper(sum, 1, 2) == 3);
    // cast from void pointer to integer and dereference
    void* (*generic_get_number)() = (void* (*)()) get_number;
    int number = *(int*) useless_wrapper(generic_get_number);
    assert(number == 12);
}