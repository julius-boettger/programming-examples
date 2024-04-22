// for later
void do_nothing() {}

// convenient syntax for nested namespaces
namespace one::two {}

//// anonymous/unnamed namespace:
// treated as if part of parent namespace (here: global)
// makes identifiers only visible to this file (like static)
// but is considered better practice than using static
namespace {
    const int not_static {};
}

namespace namespaces {
    void run_examples() {
        // call function explicitly from global namespace:
        // can be useful when multiple namespaces
        // have functions with the same name
        ::do_nothing();
        // in this example, you can also just...
        do_nothing();
        // namespace aliases exist
        namespace shorthand = one::two;
    }
}