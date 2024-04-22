// for later
void do_nothing() {}

// convenient syntax for nested namespaces
namespace one::two {}

//// anonymous/unnamed namespace
// treated as if part of parent namespace (here: global)
// makes identifiers only visible to this file (like static)
// but is considered better practice than using static
namespace {
    const int basically_static {};
}
// can also be used inside of a named namespace!
namespace named {
    namespace {
        const int basically_static {};
    }
}

//// inline namespace
// useful for versioning implementations of functions for
// backward compatability, marking the current default as inline.
// see below for more on how to call these functions!
       namespace v1 { void important_function() {} }
inline namespace v2 { void important_function() {} }

namespace namespaces {
    void run_examples() {
        //// more on inline namespaces
        // explicitly call a specific implementation
        v1::important_function();
        v2::important_function();
        // call the current default (inline) implementation
        important_function();

        //// call function explicitly from global namespace
        // can be useful when multiple namespaces
        // have functions with the same name
        ::do_nothing();
        // in this example, you can also just...
        do_nothing();

        //// namespace aliases (exist)
        namespace shorthand = one::two;
    }
}