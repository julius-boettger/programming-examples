// static: like const, but has a static lifetime too
// (needed for later example)
static HOURS_IN_A_DAY: u8 = 24;

/// examples for functions
pub fn run_examples() {
    // simple pass-by-value function
    fn sum(x: i32, y: i32) -> i32 {
        // the following two lines do the exact same thing!
        // (but only for functions? "return" can't be used with other expressions...?)
        return x + y;
        x + y // rust-syntax "tail", mind the missing ; at the end!
    }
    // call the function like this:
    let result = sum(2, 2);
    assert_eq!(result, 4);

    // functions cannot access variables of higher scopes!
    fn nothing() {
        // the following line throws an error as "result" is not accessible in this scope
        //println!("{}", result);
    }
    // return type is "void" if not specified, meaning it will return the unit type
    assert_eq!(nothing(), ());

    // pass-by-reference: (mutable) borrow as argument
    // dereferece borrowed value and increment it
    fn increment(x: &mut i32) -> () { *x += 1; }
    let mut to_increment = 0;
    increment(&mut to_increment);
    assert_eq!(to_increment, 1);

    //// ownership and moves
    // every resource can only have one owner, which is responsible
    // for freeing its memory when it's not needed anymore.

    // example struct
    #[derive(
        Debug,
        Copy, Clone // try commenting out this line! it's important later :)
    )]
    struct NumberWrapper(i32);
    // "wrapper" owns the resource of the struct instance
    let wrapper = NumberWrapper(3);

    // when a type doesn't derive Copy (!) there are two
    // ways to transfer ownership ("move" the resource):

    // move resource to other variable
    let second_owner = wrapper;
    // move resource to function by pass-by-value argument
    fn free_memory(wrapper: NumberWrapper) -> () {}
    // this will lead to the resource being freed, as it goes
    // out of scope at the end of the function which owns it
    free_memory(wrapper);
    // when a type DOES derive Copy a move will not occur, instead the resource will be copied.

    //// closures
    // closures are anonymous functions that can access variables of higher scopes
    let sum_closure       = |x: i32, y: i32| -> i32 { x + y };
    let sum_closure_short = |x: i32, y: i32|          x + y;

    // accessing variables of higher scopes is called "capturing" them.
    // each variable is captured by value, by mutable reference or by immutable reference.
    // the least invasive of these options is inferred from the context.
    // also: no arguments!
    let get_result = || result;
    // closures can be called like any other function
    assert_eq!(get_result(), result);
    // "move" forces taking ownership of captured variables.
    let own_result = move || println!("I own {}!", result);

    //// functions as function arguments
    // call a function n times
    // F is a generic type parameter
    fn call_fuction<F>(function: F, n: u8) where 
        // specify function signature of type F
        F: Fn()     -> () { // take immutable borrows of arguments
      //F: FnMut()  -> () { // take mutable borrows of arguments
      //F: FnOnce() -> () { // take ownership of arguments
        for _ in 0..n { function(); }
    }
    // try it out!
    //call_fuction(|| println!("closure speaking :)"), 3);

    //// diverging functions (never return)
    // "return" and "break" also cause some divergent behaviour, as some code will never be executed
    // mind the two return types which serve the same purpose
    use std::convert::Infallible;
    fn panic1() -> !          { panic!("something went wrong"); }
    fn panic2() -> Infallible { panic!("something went wrong"); }

    //// lifetimes
    // the compilers borrow checker gives lifetimes to borrows
    // to ensure their validity. the compiler elides (automatically infers)
    // lifetimes in a lot of common use cases, but sometimes it
    // needs explicit lifetime annotation.

    // argument x must live at least as long as this function
    fn print_ref<'a>(x: &'a i32) {
        println!("x is {}", x);
    }

    fn shouldnt_work<'a>() {
        // normal local variable (only available for this function)
        let x: bool = true;
        // reference that should live at least as long as this function
        let y: &'a bool;
        // doesn't work! x does not live long enough
        //y = &x;
    }

    // returned references must live at least as long as an input
    // (or be static)
    fn passthrough<'a>(x: &'a i32) -> &'a i32 { x }

    // 'a must live at least as long as 'b
    fn different_lengths<'a: 'b, 'b>(x: &'a i32, y: &'b i32) -> &'b i32 {
        // "coercion": 
        // x is returned with a possibly shorter lifetime than it starts with
        x
    }

    // the 'static lifetime: borrowed data lives for the whole duration the program is running
    fn static_example() -> &'static u8 {
        &HOURS_IN_A_DAY
    }

    // structs, enums and methods work in pretty much the same way
    struct Borrowed<'a>(&'a i32);

}
