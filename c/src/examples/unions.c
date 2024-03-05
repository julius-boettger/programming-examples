#include <assert.h>

void example_unions () {
    // unions are pretty similar to structs!
    // but all members are stored in the same memory location
    // => only one member can hold a value at a time
    union CharOrInt {
        char c;
        int i;
    };
    union CharOrInt my_char_or_int = { .c = 'x' };
    assert(my_char_or_int.c == 'x');
    my_char_or_int.i = 7;
    assert(my_char_or_int.i == 7);
    // the size of a union is equal to the size of its largest member
    assert(sizeof(union CharOrInt) == sizeof(int));
}