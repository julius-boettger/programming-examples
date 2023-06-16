/*

SETUP
- get rust: https://www.rust-lang.org/learn/get-started
- create new project: cargo new project-name

*/

/** entry-point of your program */
fn main() {
    //// hello world
    // the "!" signifies a macro, meaning it will be expanded to a longer code snippet at compile time
    println!("hello... world?");

    //// asserts
    // the program will panic if the expression is false
    assert!(2 == 2);

    //// the underscore _
    // assigning something to _ means to ignore the result and instantly throw it away
    let _ = 42;

    //// variables
    // declare a variable and assign a value to it afterwards:
    let first_variable;
    first_variable = 12;
    // variables are immutable by default, meaning they cannot be reassigned.
    // to declare and assign a mutable (reassignable) variable in a single line:
    let mut second_variable = 13;
    second_variable = 14; // allowed! (mutable)
    // these variables have inferred types as I did not specify one.
    // types can also be annotated manually, like i32 (signed 32-bit integer, usually the go-to)
    let integer_variable: i32 = 0;

    //// tuples
    // a tuple is a fixed-length collection of values of different types
    // as always: types can be annotated manually, but don't have to be
    let rgb_tuple: (u8, u8, u8) = (0, 255, 0);
    // values of a tuple can be extracted like this:
    let (red, green, _) = rgb_tuple;
    // ...or by their index, like this:
    let blue = rgb_tuple.2;

    //// functions
    // this is a simple function to add two numbers
    fn sum(x: i32, y: i32) -> i32 {
        // the following two lines do the exact same thing!
        return x + y; // familiar-looking syntax
        x + y // rust-syntax, mind the missing ; at the end!
    }
    // call the function like this:
    let result = sum(2, 2);
    assert!(result == 4);
    // return type is "void" if not specified, meaning it will return an empty tuple ()
    fn nothing() {}
    assert!(nothing() == ());

    //// blocks
    // blocks are expressions, which means that they evaluate to a value!
    // they are also scopes (like in most other languages)
    {
        // do something...
    };
    // the default return type (if not speficied) is an empty tuple ()
    let block = {};
    assert!(block == ());
}
