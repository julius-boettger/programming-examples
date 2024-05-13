// structs and classes are almost functionally identical.
// use structs when you only need public members,
// don't need setup/cleanup code and don't need
// getters/setters with extra logic. use classes otherwise.

#include <string>

struct Person {
// members are public by default
// this is pretty much the only difference to classes!
//public:
    // use value initialization to avoid UB!
    std::string name {};
    // member can also have other default value
    int id { 1000 };
    // can have member functions!
    std::string generate_username() {
        return name + std::to_string(id);
    }
// other access specifiers are generally
// discouraged, use classes instead
private:
};

//// templating
template <typename T>
struct Templated { T value {}; };
// alias templates
template <typename T>
using Alias = Templated<T>;

namespace structs {
    void run_examples() {
        // variable definitions are simple, although
        // typedef wasn't used! otherwise used like in C,
        // but with value / direct list initialization
        Person person1 {};
        person1.name = "foo";
        Person person2 { "bar" };
        Person person3 { .name { "foobar" } };
        // call member function
        std::string username = person1.generate_username();

        //// templating
        Templated<float> templated { 3.0f };
        // alias template
        Alias<int> alias { 3 };
        // "class templace argument deduction"
        Templated templated_long { 3l };
    }
}