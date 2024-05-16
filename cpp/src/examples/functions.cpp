#include <cassert>

//// pass by (lvalue) reference
// vs pass by value:
// - faster for big types like classes
// - probably slower for small types like int!
void double_in_place(int& x) { x *= 2; }
void const_ref(const int& x) {}

//// returning references
// make sure that returned reference
// lives beyond scope of function!
int& pass_through(int& x) { return x; }

//// constexpr and consteval functions
// constexpr" functions will be evaluated
// at compile time wherever possible
constexpr int get_special_value() {
    return 5555 + 1 - 4000 * 2342;
}
// consteval functions must be evaluated at
// compile time wherever they are used
consteval int get_other_special_value() {
    return 123 * 23 - 592 + 1111;
}
// both constexpr and consteval functions are
// implicitly inline and should be defined in header
// files if they are used by multiple source files!

//// function overloading! (is possible)
   int add(   int x,    int y) { return x + y; }
double add(double x, double y) { return x + y; }
// forbid usage of a function at compile time.
// most useful when working with overloaded functions
// (but also not that useful?)
int add(long, long) = delete;

//// default arguments
void default_arguments(int x = 5) {};
// can either be in the function
// prototype (preferred) or definition! not both!
void default_arguments2(int x = 5); // prototype
void default_arguments2(int x) {}   // definition

//// function templates
// should be placed in header files (including their
// definitions!) when called from multiple source files.
// other languages might call them "generic functions".
template <typename T> // template parameter declaration
T get_double(T x) { return x * 2; }
// abbreviated function templates: shorthand using "auto"
auto get_triple(auto x) { return x * 3; }
// non-type template parameters: useful,
// because they are constexpr, which normal
// function arguments are not allowed to be
template </*constexpr*/ float N>
float get_quadruple() {
    if constexpr (N + 1.0f > N) {}
    return N * 4.0f;
}
// combine it all!
template <auto N>
auto get_quintuple() { return N * 5; }

//// rvalue reference as argument
// can only be called with an rvalue reference
void process_ref(int&& rref) {}
// usually overloaded with a version that can
// only be called with an lvalue reference
void process_ref(int& lref) {}
// (i don't know how this could be useful)

namespace functions {
    void run_examples() {
        // pass by reference
        int x = 5;
        double_in_place(x);
        assert(x == 10);
        const_ref(5); // rvalue also works!

        // returning references: result can
        // be used as lvalue for assignment!
        pass_through(x) = 7;
        assert(x == 7);

        // constexpr variables initialized with consteval functions
        constexpr int special_value { get_special_value() };
        constexpr int other_special_value { get_other_special_value() };

        // calling function templates
         int doubled1     { get_double      (2) }; // in most cases
        char doubled2     { get_double<char>(2) }; // sometimes useful
        long tripled      { get_triple(3l) };
        float quadrupled  { get_quadruple<4.0f>() };
        double quintupled { get_quintuple<5.0 >() };

        // lvalue / rvalue reference arguments
        int& doubled_ref { doubled1 };
        process_ref(doubled_ref); // => matches lvalue ref
        process_ref(5);           // => matches rvalue ref
    }
}