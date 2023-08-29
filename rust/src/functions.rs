/// examples for functions
pub fn run_examples() {
    // simple pass by value function
    fn sum(x: i32, y: i32) -> i32 {
        // the following two lines do the exact same thing!
        // (but only for functions? "return" can't be used with other expressions...?)
        return x + y;
        x + y // rust-syntax "tail", mind the missing ; at the end!
    }

    // call the function like this:
    let result = sum(2, 2);
    assert_eq!(result, 4);

    // return type is "void" if not specified, meaning it will return the unit type
    // functions cannot access variables of higher scopes!
    fn nothing() {
        // the following line throws an error as blue is not accessible in this scope
        //println!("{}", blue);
    }

    assert_eq!(nothing(), ());

    // pass by reference: (mutable) borrow as argument
    fn increment(x: &mut i32) -> () { 
        // dereferece borrowed value and increment it
        *x += 1;
    }

    let mut to_increment = 0;
    increment(&mut to_increment);
    assert_eq!(to_increment, 1);
}
