// std::string(_view)
#include <string>
#include <string_view>

namespace strings {
    void run_examples() {
        // first of all: c-style strings
        // (char pointers / arrays) still exist, but are to be avoided.
        // but remember: c-style string literals like "hello" are
        // stored in memory for the entire runtime of the program
        char c_style_string[] = "hello";

        //// std::string
        std::string string { "better string!" };
        std::size_t string_length { string.length() };
        string = "another one?"; // reassignable with different length!
        // use "s" suffix from std::string_literals to
        // mark a string literal as type std::string
        // (default is char*)
        using namespace std::string_literals;
        auto std_string { "string literal"s };
        // can also be returned safely as it implements move semantics!

        //// std::string_view
        // basically a better const reference to any kind of string
        // (especially for function parameters!)
        std::string_view string_view { string };
        // view can also be modified without modifying original string
        string_view.remove_prefix(1); // remove first char
        // modifying/destroying the string being viewed leads to a
        // dangling/invalid string view, which usually causes UB
        string = "oh no, what happens to my string view now?";
        // can also be assigned a string literal
        string_view = "this is literally a string";
        // string view has support for constexpr, unlike string
        constexpr std::string_view constant_string { "constant :)" };
        // use "sv" suffix to create a string view literal
        using namespace std::string_view_literals;
        auto std_string_view { "string view literal"sv };
    }
}