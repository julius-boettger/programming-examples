// an example enum
enum Color {
    red,
    green,
    blue,
};

// overload unary "+" operator (usually used like "+2")
// to convert enumerator to int
constexpr int operator+(Color color) {
    return static_cast<int>(color);
}

namespace op_overloading {
    void run_examples() {
        // convert enumerator to int
        static_assert(+blue == 2);
    }
}