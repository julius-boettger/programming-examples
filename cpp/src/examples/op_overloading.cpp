#include <cassert>

// an example enum
enum Color {
    red,
    green,
    blue,
};

// overload operator~ to convert enumerator to int
int operator~(Color color) {
    return static_cast<int>(color);
}

namespace op_overloading {
    void run_examples() {
        // convert enumerator to int
        assert(~blue == 2);
    }
}