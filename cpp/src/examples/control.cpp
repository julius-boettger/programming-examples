#include <array>
#include <ranges> // for std::views::reverse

namespace control {
    void run_examples() {
        //// constexpr if statements
        // require conditional to be constant expression
        constexpr int my_constant = 3;
        if constexpr (my_constant == 3) {
            // do something
        }

        //// intentional switch fallthrough
        switch (0) {
        case 0:
            // attribute to indicate intentional fallthrough
            // not necessary, but good practice
            [[fallthrough]]; // (the semicolon is necessary)
        default:
            break;
        }

        //// for loops
        std::array<int, 3> std_array { 1, 2, 3 };
        // range-based for loop:
        // best practice! avoids indexing issues
        for (int i : std_array) {
            // do something
        }
        // can also go in reverse
        for (int i : std::views::reverse(std_array)) {
            // do something
        }
        // can also be used with (const) references to avoid
        // unnecessary copies and possibly allow element modification.
        // even better!
        for (const int& i : std_array) {
            // do something
        }

        // looping with std::size_t:
        // as the size of containers is usually of type std::size_t,
        // it is also often used for loop variables (although unsigned!)
        for (std::size_t i { 0 }; i < std_array.size(); ++i) {
            // do something
        }

        // looping with std::ssize / std::ptrdiff_t:
        // arguably safer, as no unsigned weirdness can happen
        for (std::ptrdiff_t i { 0 }; i < std::ssize(std_array); ++i) {
            // do something
        }

        // looping with pointer as iterator:
        // p is a pointer to the current element! (can be useful i guess?)
        for (auto p { std::begin(std_array) }; p != std::end(std_array); ++p) {
            // do something
        }
    }
}