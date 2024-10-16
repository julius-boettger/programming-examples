// structs and classes are almost functionally identical.
// use structs for simple requirements (more in structs.cpp).

#include <string>
#include <cassert>
#include <utility> // for std::move()
#include "examples.h"

// classes can be forward declared entirely.
// this can be useful, although it's not common
// in header files (as one might expect).
class Person;

class Person {
// members are private by default (unlike structs!)
//private:
    // non-public members are often given the prefix "m_"
    // to avoid variable shadowing and make it obvious
    // that they are members
    int m_age {};

    // static members are shared between objects.
    // they essentially are just global variables in scopes.
    // make them "inline" or "constexpr" (which is implicitly inline)
    // to allow multiple definitions for use in header files.
    static constexpr int m_life_expectancy { 75 };

    // there is a lot of stuff that can be part of a class
    using Age = int;
    enum State { hungry, full };

// only public for derived classes
protected:
    int m_just_for_the_children { 12 };

public:
    // a member function
    // use "const" to promise not to modify any member variables
    int get_age() const {
        // "this" is a pointer!
        assert(this->m_age == m_age);
        return m_age;
    }

    // static member functions are not associated with a
    // specific object (like static member variables)
    static int get_life_expectancy() {
        return m_life_expectancy;
    }

    // default constructor with empty body
    // (will also be generated implicitly
    // if no other constructor is present)
    Person() = default;
    // the following is also possible, but has some
    // unwanted implications, so avoid it
    //Person() {}

    // constructor with "member initializer list":
    // should order members like in class definition,
    // as they are also initialized in that order
    Person(int age) : m_age { age } {};

    // use "explicit" to not make this a
    // converting constructor (more on that later)
    explicit Person(const char* string) : m_age { 0 } {};

    // delegating initialization to other constructor
    Person (int age, float ignored) : Person { age } {};

    // friend functions: declare some functions as friends
    // to allow them to access non-public members
    friend void set_age_of_person(Person& person, int age);
    // can also be defined here already,
    // although they are not member functions!
    friend void friend_defined_in_class() { /* code */ }
    // friend classes can also access non-public members
    friend class PersonController;
};

// friend class
class PersonController {
public:
    static void set_age(Person& person, int age) {
        person.m_age = age;
    }
};

// friend function that accesses private member
void set_age_of_person(Person& person, int age) {
    person.m_age = age;
}

// class to demonstrate 5 special functions:
// copy constructor, copy assignment,
// move constructor, move assignment, destructor.
// copy assignment and move assignment are special operator overloads.
// all five will be implicitly generated if not defined,
// but some only under certain conditions.
// "rule of 5": if any of these 5 are defined or deleted,
// then the remaining 4 should also be defined or deleted.
class CopyMoveDestr {
public:
    // simple example member and constructor
    int m_x {};
    CopyMoveDestr(int x) : m_x { x } {};

    //// copy constructor
    // called to construct object by copying content from another object.
    // avoid side effects as they will not be triggered
    // when call to copy constructor is optimized out.
    // will be implicitly generated if not self-defined!
    CopyMoveDestr(const CopyMoveDestr& o) : m_x { o.m_x } {}

    //// copy assignment
    // similar to copy constructor: called to copy content
    // of existing object to another existing object.
    CopyMoveDestr& operator=(const CopyMoveDestr& o) {
        // detect self-assignment
		if (&o == this) { return *this; }
        // copy content
        m_x = o.m_x;
        // return reference to self
        return *this;
    }

    //// move constructor
    // similar to copy constructor: called to construct
    // object by moving content from another object.
    // useful when dealing with pointers to dynamically
    // allocated memory to transfer ownership.
    // this example is kind of bad, as we basically do a copy.
	CopyMoveDestr(CopyMoveDestr&& o) : m_x { o.m_x } {}

    //// move assignment
    // similar to move constructor: called to move content
    // of existing object to another existing object.
	CopyMoveDestr& operator=(CopyMoveDestr&& o) {
		if (&o == this) { return *this; }
		// move content
        // (bad example, we only do a copy here)
		m_x = o.m_x;
		return *this;
	}

    // destructor: called before object is destroyed
    ~CopyMoveDestr() = default;

    // all of these functions can also be explicitly
    // default-generated, e.g. the copy constructor:
    //CopyMoveDestr(const CopyMoveDestr& o) = default;
    // or just forbid calling them in the first place
    //CopyMoveDestr(const CopyMoveDestr& o) = delete;
};

// classes that need to be shared between multiple
// files should be defined in header files, like this:
class ClassInHeader {
    // all member variables need to be declared
    int m_member {};
public:
    // declare some functions, define them elsewhere
    ClassInHeader();
    // functions can also be defined already, as they are
    // implicitly inline (see include/examples.h for more)
    int get_member() const { return m_member; }
};
// then define their member functions elsewhere:
ClassInHeader::ClassInHeader() : m_member { 42 } {}

// ref qualifiers: "&" / "&&" after a member function name
class RefQual {
public:
    // "&"  => only call on lvalue implicit objects
    std::string call_type() &  { return "lvalue"; }
    // "&&" => only call on rvalue implicit objects
    std::string call_type() && { return "rvalue"; }
    // useful! e.g. to avoid returning dangling references
    // by using return-by-value only in those cases.
};

// templating
template <typename T>
class Templated {
public:
    T m_value {};
};

// constexpr: valid for contructors and member functions
class ConstClass {
public:
    constexpr ConstClass() {}
    constexpr int value() const { return 3; }
};

// helper function for later
int get_age_of_person(const Person& person) {
    return person.get_age();
}

namespace classes {
    void run_examples() {
        //// using constructors
        // call default constructor
        Person default_person {};
        assert(default_person.get_age() == 0);
        // call constructer with member initializer list
        Person person { 71 };
        assert(person.get_age() == 71);
        // call delegated constructor
        Person delegated_person { 1, 3.14f };
        assert(delegated_person.get_age() == 1);

        //// converting constructors
        // although function only accepts an argument of type
        // Person, this works, because the given int is converted
        // to a Person using the Person(int age) constructor
        assert(get_age_of_person(5) == 5);
        // the following is not allowed, as Person(char* string)
        // is "explicit" (cannot be called implicitly)
        //get_age_of_person("string");

        //// copying and moving
        const CopyMoveDestr lvalue { 3 };
        // copy constructor (construct from lvalue)
        CopyMoveDestr copy_constr { lvalue };
        assert(copy_constr.m_x == 3);
        // copy assignment (assign to lvalue)
        CopyMoveDestr copy_assign { 10 };
        copy_assign = lvalue;
        assert(copy_assign.m_x == 3);
        // move constructor (construct from rvalue)
        CopyMoveDestr move_constr { CopyMoveDestr { 4 } };
        assert(move_constr.m_x == 4);
        // move assignment (assign to rvalue)
        CopyMoveDestr move_assign { 10 };
        move_assign = CopyMoveDestr { 4 };
        assert(move_assign.m_x == 4);
        // std::move uses move instead of copy
        // constructor/assignment on lvalues
        CopyMoveDestr std_moved { std::move(lvalue) };
        assert(std_moved.m_x == 3);

        // using friends
        set_age_of_person(person, 3);
        assert(person.get_age() == 3);
        PersonController::set_age(person, 4);
        assert(person.get_age() == 4);

        // using static members
        assert(Person::get_life_expectancy() == 75);

        // using templates
        Templated<char> templated { 'x' };

        // using constexpr
        constexpr ConstClass const_obj {};
        constexpr int const_int { const_obj.value() };

        // ref qualifiers
        RefQual ref_qual {};
        assert(    ref_qual.call_type() == "lvalue");
        assert((RefQual {}).call_type() == "rvalue");
    }
}