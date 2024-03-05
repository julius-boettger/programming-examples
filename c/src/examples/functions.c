#include <assert.h>

// the simplest function
void do_nothing () {}
// can also be written like this,
// with "void" standing for "no arguments"
void do_nothing_fancy (void) {}

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
int sum_wrapper (int (*sum)(int, int), int a, int b) {
    return sum(a, b);
}
// function pointer types can be shortened in function signatures:
int sum_wrapper_2 (int sum(int, int), int a, int b) {
    return sum(a, b);
}
// can be made generic using void pointers
void* useless_wrapper (void* fn()) {
    return fn();
}

// functions can be declared without being defined,
// resulting in a "function prototype":
void defined_later();
// the compiler will then search for a definition
// somewhere else, and could find one like this:
void defined_later() {
    // do something
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