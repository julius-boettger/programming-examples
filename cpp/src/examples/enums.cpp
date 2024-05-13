// note: most of the differences of enums in
//       C vs C++ are also true for structs

//// unscoped enum
// enumerators (values like "red") are put
// into the parent namespace (here: global)
enum Color {
    red,
    green,
    blue,
};

//// scoped enum
// to avoid polluting the global namespace
// and possibly cause naming conflicts,
// put your enum in a namespace or class
namespace Direction {
    enum Direction {
        left,
        right,
        up,
        down,
    };
}

// the underlying integral base type can be
// specified explicitly (default is usually int)
enum ExplicitType: short {};

namespace enums {
    void run_examples() {
        // variable definitions are simple,
        // although typedef wasn't used!
        Color color { red };
        // assignment using integer value and static_cast
        color = static_cast<Color>(0);

        //// these actually cause errors!
        //Color color { white };
        // only works if base is specified
        //Color color { 0 };

        // use scoped enums like this
        Direction::Direction direction { Direction::up };
    }
}