/// examples of control structures and general flow of control
pub fn run_examples() {
    //// if, else if, else
    // blocks are expressions + after "if" comes a block => if-expressions!

    if true {
        "the boolean expression is true!";
    } else if false {
        "this will never be reached";
    } else {
        "and this is also unecessary";
    }

    let returned_by_if = if true {
        "true"
    } else {
        "false"
    };

    //// loop 
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
        // j will be 1, 2, 3
    }
}
