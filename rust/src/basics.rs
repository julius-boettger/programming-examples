/// examples for basic syntax and concepts (this is a doc comment)
// if you are wondering about "pub", see modules.rs
// if you are wondering about "fn run_examples() {", see functions.rs
pub fn run_examples() {
    //// comments
    // normal comment
    /* block comment */
    //! this is a doc comment inside a function, can also be outside with "///"

    //// hello world (and printing to console)
    // the "!" signifies a macro, meaning it will be expanded to a longer code snippet at compile time
    // see the dedicated file macros.rs for more about macros
    println!("hello... world?");
    // print! also exists
    // eprint! and eprintln! are for errors

    //// asserts
    // the program will panic if two expressions do not have the same value
    assert_eq!(2, 2);

    //// variables, (im)mutability, references/borrowing
    // variables are allocated on the stack by default
    let first_variable;
    first_variable = 12;
    // variables are immutable by default, meaning they cannot be reassigned.
    // the following variable is mutable (reassignable):
    let mut second_variable = 13;
    second_variable = 14; // allowed! (mutable)
    // these variables have inferred types as i did not specify one.
    // types can also be annotated manually, like i32 (signed 32-bit integer, usually the go-to)
    let integer_variable: i32 = 0;
    // this variable contains a memory address ("borrow")
    let second_variable_borrow = &second_variable;
    // this variable gets assigned the value of the address (dereference)
    // changing the value of this will not affect the original variable!
    let second_variable_copy = *second_variable_borrow;
    // mutable borrows (&mut) can be modified when dereferenced
    let second_variable_mut_borrow = &mut second_variable;
    *second_variable_mut_borrow += 1;
    // this... is possible
    let too_many_borrows = ***(&&&&&first_variable);
    assert_eq!(second_variable, 15);

    //// heap allocation
    // variables are allocated on the stack by default, which is fast,
    // but requires the compiler to know the size of the object beforehand.
    // if thats not possible, heap allocation is an option:
    let mut heap_allocated = Box::new("this is on the heap!");
    // boxes are smart pointers and can be dereferenced
    *heap_allocated = "new string";
    
    // constants: need to have their type annotated explicitly
    const DAYS_IN_A_YEAR: u16 = 365;
    // underscore: assigning something to _ means to ignore the result and instantly throw it away
    let _ = 42;
    // boolean operations: not, and, or
    let logic = (!false && true) || false;

    //// type aliases
    // new names for existing types!
    type ColorValue = u8;
    let grey_scale: ColorValue = 127;

    //// ranges and range notation
    // ranges are used in array slicing, for loops, ...
    // first number is inclusive, second is exclusive
    let range = 1..5; // 1, 2, 3, 4
    // "=" makes second number inclusive too
    let range_inclusive = 1..=5; // 1, 2, 3, 4, 5
    // this also exists
    let range_to = ..5; // x < 5
    let range_to_inclusive = ..=5; // x <= 5
    let range_from = 1..; // x >= 1

    //// primitive data types
    let data_types: (
        // signed integers (can be negative)
        i8, i16, i32, i64, i128, isize, // isize depends on architecture, e.g. 32b => 32b
        // unsigned integers (cannot be negative)
        u8, u16, u32, u64, u128, usize, // usize depends on architecture, e.g. 32b => 32b
        // signed floating points
        f32, f64,
        bool, // boolean, true or false
        char, // char, 'A'
        &str, // "string slice", "hello"
        (), // "unit" type (only possible value is empty tuple)
    );

    //// number notations
    let decimal     =   10;
    let hexadecimal = 0xA;    // => 10
    let octal       = 0o12;   // => 10
    let binary      = 0b1010; // => 10
    // underscores can be inserted to improve readability
    let big_number = 1_000_000_000;
    // f64 can use scientific e notation
    let small_number = 1e-10;
    // literals can have a type as a suffix, which is generally a good practice
    let specific_number: f32 = 1f32; // same as 1.0

    //// casting
    // rust has no implicit type conversion. it can only be done explicitly:
    let small_int: u8 = 1.2_f64 as u8;

    //// compound data type: tuple
    // fixed-length collection of values of different types
    // as always: types can be annotated manually, but don't have to be
    let rgb_tuple: (u8, u8, u8) = (0, 255, 0);
    // values of a tuple can be extracted like this:
    let (red, green, _) = rgb_tuple;
    // ...or by their index, like this:
    let blue = rgb_tuple.2;

    //// compound data type: array (and array slice)
    // fixed-length collection of same type
    let array = [1, 10, 100, 1000];
    // type is combination of type and length
    let typed_array: [bool; 2] = [true, false];
    // initialize all elements with the value -1
    let default_value_array: [i32; 10] = [-1; 10];
    // element of index 
    let first_element = array[0]; // => 1
    // safely get element of index as an option
    let first_element_option = array.get(342); // => None
    // length of array
    let length = array.len(); // => 3
    // array slices are parts of an existing array that can be retreived using ranges
    let array_slice: &[i32] = &array[1..=2]; // index 1 and 2

    //// compound data type: vector
    // vectors are resizable arrays
    let mut vector = vec![1, 2, 3];
    vector.push(4);
    // iteration
    for  x            in vector.iter()             {}
    for  x        in vector.iter_mut()         {} // mutable!
    for (x, i) in vector.iter().enumerate() {} // with index!
    // vectors can also be collected from iterators
    let collected: Vec<u8> = (0..10).collect();

    //// compound data type: string
    // string slice: supposed to be immutable
    let string_slice: &str = "this can never be changed";
    // String object: supposed to be mutable
    let mut string_object: String = String::from(string_slice);
    string_object.push_str("... but this can!");
    // String from &str: two options
    let _ = String::from("option 1");
    let _ =              "option 2".to_owned();

    //// blocks, scopes, variable shadowing, freezing
    // we will need this later...
    let mut mutable_var = 0;
    // blocks are expressions, which means that they evaluate to a value!
    // this also counts for blocks used in all kinds of loops, if-expressions, ...
    // functions are an exception! returning their values and scopes are a bit different
    // they are also scopes (like in most other languages)
    {
        // variables of higher-up scopes are accessible:
        let blue_ref = &blue;
        // variable shadowing is possible!
        // the following variable now shadows "blue" from the outer scope
        let blue = "this is allowed!";
        // even this is allowed? variable shadowing in the same scope?
        let blue = 2;
        // mutable variables from outer scopes can be "frozen"
        // this means shadowed by an immutable variant
        let mutable_var = mutable_var;
        //mutable_var += 1; is not allowed! variable is immutable in this scope!
    };
    // this is allowed here, as variable is not shadowed by an immutable copy anymore
    mutable_var += 1; 
    // the default return type (if not speficied) is the unit type
    let block = {};
    assert_eq!(block, ());
    // blocks return their last expression without a semicolon
    // the keyword "return" can not be used!
    let block_with_value = {
        let x = 4u128;
        x
    };
    assert_eq!(block_with_value, 4);

    //// Rc: reference counted (thread-unsafe!)
    // tracks number of references to the wrapped value.
    // counter is increased when Rc is cloned, which just
    // creates another pointer to the wrapped value.
    // Rc and wrapped value are dropped when counter is 0.
    // all reference holders are owners (multiple owners!)
    use std::rc::Rc;
    let rc = Rc::new("this is reference counted and stuff");
    // there is exactly one reference to the wrapped value after initialization
    assert_eq!(1, Rc::strong_count(&rc));
    // borrow
    let rc_borrow = Rc::clone(&rc);
    assert_eq!(2, Rc::strong_count(&rc));

    //// Arc: atomically reference counted => Rc but thread-safe
    use std::sync::Arc;
    let arc = Arc::new("reference counted & thread safe");
}

// module for unit testing the parent module
// run with "cargo test"
#[cfg(test)]
mod tests {
    // use stuff from parent scope, often useful
    use super::*;
    // a test case will fail if it panics
    #[test] fn will_pass() { assert_eq!(2 + 2, 4); }
    #[test] fn will_fail() { panic!(); }
}