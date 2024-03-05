#include <assert.h>

void example_enums () {
    // an enum(eration) is used to assign names to integer constants
    enum DaysOfWeek { Mo, Tu, We, Th, Fr, Sa, Su };
    // the first element is assigned the value 0,
    // the following elements are increments
    assert(Mo == 0);
    assert(Tu == 1);
    // a variable with the defined enum type
    enum DaysOfWeek day = We;
    // assigning the corresponding integer value is allowed
    day = 0;
    // this is allowed... but don't!
    day = -1;
    // integer value does not have to be stored in an enum variable!
    int not_enum = Fr;
    // integer values can also be set explicitly
    enum Example { Constant = -1612 };
}