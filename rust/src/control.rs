/// examples of control structures and general flow of control
pub fn run_examples() {
    //// if, else if, else
    if true {
        "the boolean expression is true!";
    } else if false {
        "this will never be reached";
    } else {
        "and this is also unecessary";
    }
    // blocks are expressions and after "if" comes a block => if-expressions!
    let returned_by_if = if true {
        "true"
    } else {
        "false"
    };

    //// match
    // like "switch" in other languages, but all possible options must be covered
    // only evaluates the first matching "arm" ("case" in other languages)
    let number = -2;
    let result: &str = match number { // is also an expression!
        0 => "yeah pretty cool number",
        // ranges
        1..=1 => "haha, haha, one!",
        // "bindings": assign name to value to use it when evaluating the arm
        // (-1 could also be a range)
        n @ -1 => {
            // can also use blocks here
            let x = n + 1;
            "yeeeah pretty cool number"
        },
        // "guards": use boolean to match value
        // (value is also assigned a name, like with bindings)
        n if n >= 0 => "thats... positive",
        // match all possible values, should be last arm
        _ => "idk what that is"
    };
    //// match expressions can destructure some types into their components
    // tuples
    let result: &str = match (1, 2, 3) {
        (0, 0, 0) => "all three values are 0",
        (0, _, 0) => "a and c are 0", // second value doesnt matter
        (0, b, c) => "a is 0, b and c are... something",
        (1, .., 1) => "a and c are 1", // all values between first and last dont matter
        (1, ..) => "a is 1",
        (.., 1) => "c is 1",
        (a, b, c) => "all values are... something"
    };
    // arrays
    let result: String = match [1, 2, 3] {
        // everything for tuples also applies
        [0, ..] => "first value is 0".to_owned(),
        // store middle part in a new array
        [first, middle @ .., last] =>
            format!("first: {}, middle: {:?}, last: {}", first, middle, last)
    };
    // structs
    struct Struct { a: u8, b: u8, c: u8 }
    let result: &str = match (Struct { a: 1, b: 2, c: 3 }) {
        // ignore some fields, expect values on others
        Struct { a: 1, b, .. } => "a is 1, b is something, rest doesnt matter",
        // rename fields
        Struct { a: x, b: y, c: z } => "renamed",
    };
    // borrows
    let mut value = 5;
    match value {
        // the matched value is modifiable by matching a mutable borrow
        ref mut value => {
            *value = 10;
        }
    }
    assert_eq!(value, 10);
    // enums
    enum Color {
        Red, Green, Blue,
        RGB(u8, u8, u8)
    }
    let result: &str = match Color::Red {
        Color::Blue => "blue :)",
        // destructure like normal tuple (same with structs, ...)
        Color::RGB(r, .., b) => "rgb",
        _ => "dont care"
    };

    //// loops
    // loop: executes indefinitely until a break is reached
    let mut i = 0;
    loop {
        i += 1;
        if i < 10 {
            continue; // this keyword exists!
        } else {
            break;
        }
    }
    assert_eq!(i, 10);

    // while
    while i > 0 {
        i -= 1;
    }
    assert_eq!(i, 0);

    // for loop with range notation
    for j in 1..=3 {
        // j will be 1, 2, 3 (see ranges)
    }
    // this would do something 3 times with no iterating variable
    for _ in 0..3 {}

    //// if let (else): improved enum matching
    // only execute block if enum can successfully be destructured...
    let result: String = if let Some(number) = Some(3) {
       format!("got number: {}", number)
    } else {
        "no number :(".to_owned()
    };
    // ...or if enum matches
    if let None = None::<bool> {
        // something happens!
    }
    // bindings are allowed!
    // also notice the single "=" (not "=="), which means that
    // implementing PartialEq for comparisons is not required!
    if let Some(value @ 100..) = Some(128) {
        // something happens!
    }

    //// while let: improved matching in loops (similar to if let)
    let mut optional_counter = Some(0);
    // while enum can be destructured
    while let Some(i) = optional_counter {
        if i > 9 { optional_counter = None; }
        else { optional_counter = Some(i + 1) }
    }

    //// let else: diverge if something fails
    // try to bind a variable, diverge (panic, return, break, ...) if it fails
    let x = 3 else {
        panic!("I thought this couldn't go wrong...!?")
        //return
        //break
    };
    // if the program reaches this point we can be sure that x was assigned successfully
    let success = format!("nice! {} works!", x);

}
