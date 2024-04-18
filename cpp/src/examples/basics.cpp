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
        int       value_init {};      // best practice to use default value like 0
        int direct_list_init { 3 };   // best practice to use given value
        int   copy_list_init = { 4 }; // less common/preferred than the other two
        // initializing multiple variables of the same type like this is possible!
        int x{1}, y(2), z = 3;

        //// new data types!
        bool boolean { true };
        // larger, implementation-defined char, deprecated
        wchar_t wchar { 0 };
        // larger chars with guaranteed sizes
        char16_t char16; char32_t char32;
        // better integer types, similar to C
        // 8 bit variants are usually treated chars (e.g. when printing)
        std::uint8_t uint8;
        std::uint_fast8_t fast_uint8;
        std::uint_least8_t least_uint8;

        // preferred way for explicit casting: static_cast
        // will produce UB if value doesn't fit in new type
        int int_from_float { static_cast<int>(5.432f) };

        // reliable built-in binary notation
        // also: ' as digit separator!
        unsigned char binary { 0b1101'0010 };

        // better constants with constant expressions
        // have to be evaluable at compile time!
        // best practice wherever possible
        constexpr long constant { 10 * 245 - 300 };
    }
}