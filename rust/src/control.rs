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

    // for: only option is what other languages call "for-each":
    for j in 1..=3 {
        // j will be 1, 2, 3 (see ranges)
    }
    // this would do something 3 times with no iterating variable
    for _ in 0..3 {}
}
