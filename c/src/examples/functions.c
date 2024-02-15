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

void example_functions () {
    // call the funtions declared above

    do_nothing();

    assert(get_double(2) == 4);

    int x = 3;
    double_in_place(&x);
    assert(x == 6);
}