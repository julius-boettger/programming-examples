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

namespace functions {
    void run_examples() {
        constexpr int special_value { get_special_value() };
        constexpr int other_special_value { get_other_special_value() };
    }
}