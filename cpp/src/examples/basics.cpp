// better integers like std::uint8_t
#include <cstdint>
// for assert()
#include <cassert>

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

        // type aliasing (preferred over c-style typedef)
        using Distance = int;
        // useful for function pointers!
        using Predicate = bool (*)();
        Predicate test_if_equal { nullptr };

        // type inference, useful for when type doesn't really matter
        auto dont_care_about_type = 3.23L;
        // usually just infers the basic type, so
        // extra modifiers should be applied explicitly
        constexpr auto& ref_to_constant = constant;

        //// explicit casting
        // c-style: available for compatability, bad practice.
        int c_style_casted1 { (int) 5.432f };
        int c_style_casted2 {  int(5.432f) }; // also possible!
        // static_cast: best practice, but will
        // produce UB if value doesn't fit in new type
        int statically_casted { static_cast<int>(5.432f) };
        // const casts / reinterpret casts: bad practice,
        // cause more harm than useful behavior on average

        //// lvalue and rvalue expressions
        // "rvalue expressions" evaluate to temporary values
        5;
        // "lvalue expressions" evaluate to identifiable objects
        // also differentiate between "modifiable" and "non-modifiable"!
        boolean;
        // if an rvalue is expected but an lvalue supplied,
        // implicit conversion will take place
        bool bool2 { boolean }; // lvalue "boolean" => rvalue "true"

        //// (raw) pointers
        // exist, but are to be avoided
        bool* bool_pointer = &boolean;
        // C++ nullptr == C null
        void* null { nullptr };

        //// dynamic memory allocation
        // request dynamic memory with the size of an int
        // and assign the resulting address to a pointer.
        // will throw an exception if allocation fails.
        int* heap_int { new int };
        *heap_int = 5;
        // provide a value during initialization
        int* init_heap_int { new int { 4 } };
        assert(*init_heap_int == 4);
        // don't forget to free the memory!
        delete heap_int;
        delete init_heap_int;
        // optionally set the pointer to nullptr
        // afterwards to avoid UB when using
             heap_int = nullptr;
        init_heap_int = nullptr;
        // special notation for arrays
        int* heap_array { new int[3] {} };
        delete[] heap_array;

        //// (lvalue) references
        // - preferred over raw pointers
        // - must be initialized immediately
        // - can not be reseated later
        // - the "&" means "lvalue reference" here, not "address of"
        int non_const_int = 1;
        int& non_const_ref { non_const_int };
        const int const_int = 2;
        const int& const_ref { const_int };
        // const reference to non-const variable
        const int& const_ref_to_non_const { non_const_int };
        // const reference to rvalue
        const int& const_ref_from_rvalue { 2 };
        // constexpr references: can only be
        // bound to global or static variables
        static int static_int { 4 };
        constexpr int& static_int_ref { static_int };
        // use another "const" for constants!
        const static int const_static_int { 5 };
        constexpr const int& const_static_int_ref { const_static_int };

        //// rvalue references
        // rvalue references are references initialized with
        // rvalues. this creates a reference to a temporary
        // object with extended lifetime. may not seem
        // very useful here, see more in functions.cpp.
        int&& rref { 5 };
        // value can be modified!
        rref = 6;
        assert(rref == 6);
    }
}