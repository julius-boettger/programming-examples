// better integers like std::uint8_t
#include <cstdint>

// for later
void do_nothing() {}

namespace basics {
    // convenient syntax for nested namespaces
    namespace one::two {}

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

        //// new data types!
        bool boolean { true };
        // larger, implementation-defined char, deprecated
        wchar_t wchar;
        // chars with guaranteed sizes (preferred!)
        char8_t char8;
        char16_t char16;
        char32_t char32;
        // better integer types, similar to C
        // 8 bit variants are usually treated chars (e.g. when printing)
        std::uint8_t uint8;
        std::uint_fast8_t fast_uint8;
        std::uint_least8_t least_uint8;

        //// namespaces
        // call function explicitly from global namespace:
        // can be useful when multiple namespaces
        // have functions with the same name
        ::do_nothing();
        // in this example, you can also just...
        do_nothing();
        // namespace aliases exist
        namespace shorthand = basics::one::two;

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

        // many operators have alternative, equivalent keywords
        // https://en.cppreference.com/w/cpp/language/operator_alternative
        bool condition { (!true && false) || (false and (not true or false)) };
    }
}