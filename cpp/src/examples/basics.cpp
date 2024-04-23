// better integers like std::uint8_t
#include <cstdint>

// better constants with constant expressions:
// have to be evaluable at compile time!
// best practice wherever possible
extern constexpr long constant { 10 * 245 - 300 };
// when initializing with "extern constexpr", other files
// have to use "extern const" for their forward declarations
// (because compile time evaluation is not possible)
extern const long constant;

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

        // reliable built-in binary notation
        // also: ' as digit separator!
        unsigned char binary { 0b1101'0010 };

        // many operators have alternative, equivalent keywords
        // https://en.cppreference.com/w/cpp/language/operator_alternative
        bool condition { (!true && false) || (false and (not true or false)) };

        // new type of assert that is checked at compile time
        // (not runtime) and has an optional diagnostic message
        static_assert(true, "true was not true???");

        //// explicit casting
        // c-style: available for compatability, bad practice.
        int c_style_casted1 { (int) 5.432f };
        int c_style_casted2 {  int(5.432f) }; // also possible!
        // static_cast: best practice, but will
        // produce UB if value doesn't fit in new type
        int statically_casted { static_cast<int>(5.432f) };
        // const casts / reinterpret casts: bad practice,
        // cause more harm than useful behavior on average
    }
}