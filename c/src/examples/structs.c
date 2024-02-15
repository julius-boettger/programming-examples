#include <assert.h>
// for strcpy()
#include <string.h>

void example_structs () {
    // structs...
    // - can't have associated functions (like constructors)
    // - can't hide data (everything is "public")
    struct Person {
        // "members"
        unsigned short age;
        char name[20]; // string
    };

    // declare a variable of the defined struct
    struct Person person;
    // assign values to its members
    person.age = 72;
    strcpy(person.name, "someone"); // normal assignment doesn't work
    // shorthand initialization (order matters!)
    struct Person person2 = { 0, "someone else" };
    // other shorthand initialization (order doesn't matter)
    struct Person person3 = { .age = 0, .name = "someone else" };

    // copy struct content (copy! not reference)
    struct Person person_copy = person;

    // shorthand for declaring a variable of a struct
    struct IntWrapper { int value; } myIntWrapper = { 2 };
    assert(myIntWrapper.value == 2);

    // "structure padding" occurs by default:
    // members are aligned to memory using empty bytes in-between
    // to minimize cpu read cycles when reading their values.
    // you can use "structure packing" like this to remove the
    // padding, resulting in a smaller memory footprint:
    struct MemoryEfficient {
        char value1;
        int value2;
    }  __attribute((packed)) __;
    // => size is 5 bytes instead of 8

    // 1 bit sized member (value can only be 0 or 1)
    struct Boolean {
        unsigned int value : 1; // <= size of member in bits (!)
    } myBoolean = { 1 };
}