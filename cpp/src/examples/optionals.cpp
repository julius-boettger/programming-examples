#include <cassert>

// for std::optional
#include <optional>
using std::optional;

namespace optionals {
    void run_examples() {
        // an optional either contains a value or doesn't
        optional<int> value { 0 };
        optional<int> no_value {};

        //// check for value 
        assert(value.has_value());
        // or just with implicit bool conversion
        assert(value);
        assert(!no_value);

        // std::nullopt means "no value"
        optional<int> explicit_no_value { std::nullopt };
        assert(!explicit_no_value);

        //// acquiring the value
        // .value_or(_): uses provided fallback if no value
        assert(no_value.value_or(7) == 7);
        // .value(): throws exception if no value
        assert(value.value() == 0);
        // dereference: UB if no value
        assert(*value == 0);
    }
}