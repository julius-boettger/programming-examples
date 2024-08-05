#include <cassert>

// for ellipsis
#include <cstdarg>
// for std::function
#include <functional>

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

//// ellipsis ("...")
// allow an unknown number of arguments of unknown types
// needs to have at least one normal parameter
// to be avoided! missing type checking is dangerous
int ellipsis_sum(int count, ...) {
    int sum { 0 };
    // get ellipsis arguments
    va_list args;
    // initialize with last non-ellipsis argument
    va_start(args, count); 
    for (int i { 0 }; i < count; ++i) {
        // get the next argument as an integer
        sum += va_arg(args, int);
    }
    // clean up
    va_end(args);
    return sum;
}

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

        // ellipsis
        assert(ellipsis_sum(0) == 0);
        assert(ellipsis_sum(3, 1, 2, 3) == 6);
        // makes no sense, but is allowed!
        ellipsis_sum(100, 0.23f, "test");

        //// lambdas (aka. closures / anonymous functions)
        // type alias for function pointer (for readability)
        using SumFunction = int (*)(int, int);
        // lamda for sum of two ints
        // with function pointer type, which is the only possible type
        // that only supports empty capture clauses (more later)
        SumFunction lambda_sum1 = [](int a, int b) -> int { return a + b; };
        assert(lambda_sum1(1, 2) == 3);
        // return type is optional, assumes auto if missing
        SumFunction lambda_sum2 = [](int a, int b) { return a + b; };
        assert(lambda_sum2(3, 4) == 7);
        // parameter list can be empty or missing entirely
        int (*lambda_value1)() = []() { return 1; };
        int (*lambda_value2)() = []   { return 2; };
        // shortest possible lambda
        void (*lambda)() = [] {};
        // call lambda inline immediately after definition
        [](){}();
        // using auto is the only way to get the lambdas type precisely
        // as the compiler generates a unique type for each lambda.
        // this is the preferred type for most lambdas, as it 
        // comes with the additional benefit of no overhead.
        auto lambda_value3 = [] { return 3; };
        // this is also a valid, with or without explicit types
        std::function<int()> lambda_value4 = [] { return 4; };
        std::function        lambda_value5 = [] { return 5; };
        // abbreviated function templates for generic lambdas
        auto lambda_generic_sum = [](auto a, auto b) { return a + b; };
        assert(lambda_generic_sum(3.0f, 3.2f) == 6.2f);
        // lambdas are implicitly constexpr if possible
        constexpr auto lambda_const = [] { return 3.14; };
        // capture clauses (defined in the square brackets):
        // give lambda access to objects with non-static lifetimes.
        // objects with static lifetimes are always allowed:
        static int static_var = 4;
        assert([] { return static_var; }() == static_var);
        // otherwise capture clauses are necessary
        int var = 1;
        assert([var] { return var; }() == var);
        // captured variables are copies, not references!
        // they are also const by default. allow mutation
        // of the lambdas copy of the captured variable:
        [var] mutable { ++var; }(); // => var == 2
        assert(var == 1); // unchanged
        // capturing by reference is also possible
        [&var] { ++var; }();
        assert(var == 2); // changed this time!
        // default captures: capture all mentioned variables
        // by value
        assert([=] { return var; }() == var);
        // by reference
        [&] { ++var; }();
        assert(var == 3);
    }
}