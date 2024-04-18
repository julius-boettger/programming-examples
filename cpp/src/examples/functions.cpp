// functions that can be evaluated at compile
// time should also be marked with constexpr
constexpr int get_special_value() {
    return 123 * 23 - 592 + 1111;
}

namespace functions {
    void run_examples() {
        constexpr int special_value { get_special_value() };
    }
}