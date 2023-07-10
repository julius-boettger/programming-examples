/// examples for basic syntax and concepts (this is a doc comment)
// "pub" is needed to make this function public, meaning accessible by other files when importing as a module
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

    //// variables
    let first_variable;
    first_variable = 12;
    // variables are immutable by default, meaning they cannot be reassigned.
    // the following variable is mutable (reassignable):
    let mut second_variable = 13;
    second_variable = 14; // allowed! (mutable)
    // these variables have inferred types as I did not specify one.
    // types can also be annotated manually, like i32 (signed 32-bit integer, usually the go-to)
    let integer_variable: i32 = 0;
    // this variable contains a memory address (pointer)
    let second_variable_pointer = &second_variable;
    // this variable gets assigned the value of the address (dereferenced pointer)
    // changing the value of this will not affect the original variable!
    let second_variable_copy = *second_variable_pointer;
    // mutable pointers (&mut) can be modified when dereferenced
    let second_variable_mut_pointer = &mut second_variable;
    *second_variable_mut_pointer += 1;
    assert_eq!(second_variable, 15);

    //// the underscore _
    // assigning something to _ means to ignore the result and instantly throw it away
    let _ = 42;

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
        i8, i16, i32, i64, isize, // isize depends on architecture, e.g. 32b => 32b
        // unsigned integers (cannot be negative)
        u8, u16, u32, u64, usize, // usize depends on architecture, e.g. 32b => 32b
        // signed floating points
        f32, f64,
        bool, // boolean, true or false
        char, // char, 'A'
        &str, // "string slice", "hello"
        (), // "unit" type (only possible value is empty tuple)
    );

    // integer values can be written in different numeral systems
    let decimal     =   10;
    let hexadecimal = 0xA;    // => 10
    let octal       = 0o12;   // => 10
    let binary      = 0b1010; // => 10
    // underscores can be inserted to improve readability
    let big_number = 1_000_000_000;
    // f64 can use scientific e notation
    let small_number = 1e-10;
    // literals can have a type as a suffix
    let specific_number: f32 = 1f32; // same as 1.0

    //// boolean operations: not, and, or
    let logic = (!false && true) || false;

    //// compound data type: tuple
    // fixed-length collection of values of different types
    // as always: types can be annotated manually, but don't have to be
    let rgb_tuple: (u8, u8, u8) = (0, 255, 0);
    // values of a tuple can be extracted like this:
    let (red, green, _) = rgb_tuple;
    // ...or by their index, like this:
    let blue = rgb_tuple.2;

    //// compound data type: array
    // fixed-length collection of same type
    let array = [1, 10, 100, 1000];
    // type is combination of type and length
    let typed_array: [bool; 1] = [true];
    // initialize all elements with the value -1
    let default_value_array: [i32; 10] = [-1; 10];
    // element of index 
    let first_element = array[0]; // => 1
    // length of array
    let length = array.len(); // => 3
    // array slices are parts of an existing array that can be retreived using ranges
    let array_slice: &[i32] = &array[1..=2]; // index 1 and 2

    //// compound data type: string
    // string slice: supposed to be immutable
    let string_slice: &str = "this can never be changed";
    // String object: supposed to be mutable
    let mut string_object: String = String::from(string_slice);
    string_object.push_str("... but this can!");

    //// blocks
    // blocks are expressions, which means that they evaluate to a value!
    // they are also scopes (like in most other languages)
    {
        // variables of higher-up scopes are accessible:
        //println!("{}", blue);
    };
    // the default return type (if not speficied) is the unit type
    let block = {};
    assert_eq!(block, ());
}
