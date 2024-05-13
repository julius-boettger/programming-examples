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
// or use this cool shorthand! "enum classes"
// also has some other benefits, see use below
enum class State {
    ready,
    running
};

// the underlying integral base type can be
// specified explicitly (default is usually int)
enum ExplicitType: short { value };

namespace enums {
    void run_examples() {
        // variable definitions are simple,
        // although typedef wasn't used!
        Color color { red };
        // assignment using integer value and static_cast
        color = static_cast<Color>(0);

        //// these actually cause errors!
        //Color color { white };
        //Color color { 0 };

        // scoped enums (with explicit namespace)
        Direction::Direction direction { Direction::up };
        // enum classes avoid some redundancy!
        State state { State::ready };
        // can also import enumerators into current scope
        using enum State;
        State short_state { running };

        // this works when base is specified
        // or enum is enum class
        ExplicitType explicit_type { 0 };
        State another_state { 0 };
    }
}