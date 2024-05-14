// structs and classes are almost functionally identical.
// use structs for simple requirements (more in structs.cpp).

#include <cassert>

class Person {
// members are private by default (unlike structs!)
//private:
    // non-public members are often given the prefix "m_"
    // to avoid variable shadowing and make it obvious
    // that they are members
    const int m_age {};

// only public for derived classes
protected:
    int m_just_for_the_children { 12 };

public:
    // a member function
    // use "const" to promise not to modify any member variables
    int get_age() const {
        return m_age;
    }

    // default constructor with empty body
    // (will also be generated implicitly
    // if no other constructor is present)
    Person() = default;
    // the following is also possible, but has some
    // unwanted implications, so avoid it
    //Person() {}

    // define own copy constructor: is called when object
    // is initialized with other object of same type.
    // avoid side effects as they will not be triggered
    // when call to copy constructor is optimized out.
    // will be implicitly generated if not self-defined!
    Person(const Person& person) : m_age { person.get_age() } {}
    // can also be explicitly generated
    //Person(const Person& person) = default;
    // or just forbid making copies in the first place
    //Person(const Person& person) = delete;

    // constructor with "member initializer list":
    // should order members like in class definition,
    // as they are also initialized in that order
    Person(int age) : m_age { age } {};

    // use "explicit" to not make this a
    // converting constructor (more on that later)
    explicit Person(const char* string) : m_age { 0 } {};

    // delegating initialization to other constructor
    Person (int age, float ignored) : Person { age } {};

    // destructor: called before object is destroyed
    ~Person() = default;
};

// helper function for later
int get_age_of_person(const Person& person) {
    return person.get_age();
}

namespace classes {
    void run_examples() {
        // call default constructor
        Person default_person {};
        assert(default_person.get_age() == 0);
        // call constructer with member initializer list
        Person person { 71 };
        assert(person.get_age() == 71);
        // call delegated constructor
        Person delegated_person { 1, 3.14f };
        // call copy constructor
        Person copied_person { person };
        assert(copied_person.get_age() == 71);

        //// converting constructors
        // although function only accetps an argument of type
        // Person, this works, because the given int is converted
        // to a Person using the Person(int age) constructor
        assert(get_age_of_person(5) == 5);
        // the following is not allowed, as Person(char* string)
        // is "explicit" (cannot be called implicitly)
        //get_age_of_person("string");
    }
}