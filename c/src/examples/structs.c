// for strcpy()
#include <string.h>

void example_structs () {
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
    struct Person person2 = {0, "someone else"};

    // copy struct content (copy! not reference)
    struct Person person3 = person2;
}