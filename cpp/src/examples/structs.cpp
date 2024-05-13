#include <string>

struct Person {
    // use value initialization to avoid UB!
    std::string name {};
    // member can also have other default value
    int id { 1000 };
};

// can also use templating
template <typename T>
struct Templated { T value {}; };

namespace structs {
    void run_examples() {
        // variable definitions are simple, although
        // typedef wasn't used! otherwise used like in C,
        // but with value / direct list initialization
        Person person1 {};
        person1.name = "foo";
        Person person2 { "bar" };
        Person person3 { .name { "foobar" } };

        // templating
        Templated<float> templated { 3.0f };
    }
}