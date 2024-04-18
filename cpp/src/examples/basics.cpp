// better integers like std::uint8_t
#include <cstdint>

namespace basics {
    void run_examples() {
        //// types of initialization
        int default_init;     // => garbage value
        int  direct_init(2);  // confusing, looks like function call
        int    copy_init = 1; // a.k.a. "c-style", copy from right to left
        // list/uniform/brace initialization methods
        // are usually preferred!
        int       value_init{ };    // best practice, uses default value like 0
        int direct_list_init{3};    // best practice!
        int   copy_list_init = {4}; // less common/preferred than the other two
        // initializing multiple variables of the same type like this is possible!
        int x{1}, y(2), z = 3;

        //// new data types!
        bool boolean = true;
        // larger, implementation-defined char, deprecated
        wchar_t wchar = 0;
        // larger chars with guaranteed sizes
        char16_t char16; char32_t char32;
        // better integer types, similar to C
        std::uint8_t uint8;
        std::uint_fast8_t fast_uint8;
        std::uint_least8_t least_uint8;
    }
}