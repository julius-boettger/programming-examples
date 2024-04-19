// "constexpr" functions will be evaluated
// at compile time wherever possible
constexpr int get_special_value() {
    return 5555 + 1 - 4000 * 2342;
}
// "consteval" functions must be evaluated at
// compile time wherever they are used
consteval int get_other_special_value() {
    return 123 * 23 - 592 + 1111;
}
// both "constexpr" and "consteval" functions are
// implicitly inline and should be defined in header
// files if they are used by multiple source files!

namespace functions {
    void run_examples() {
        constexpr int special_value { get_special_value() };
        constexpr int other_special_value { get_other_special_value() };
    }
}