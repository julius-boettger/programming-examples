/// examples for macros
pub fn run_examples() {

    // macros look like functions with a bang ("!"),
    // but instead of getting executed at compile time, they get
    // replaced with regular source code ("expanded") before compilation

    // this will just expand into the literal "1"
    macro_rules! one {
        () => {
            1
        };
    }
    assert_eq!(one!(), 1);

    // this expands into a funtion with the given name and an empty body
    macro_rules! create_useless_function {
        // "name" is the name of the argument
        // "ident" is the "designator", meaning the type of argument.
        // in this case "ident" stands for an identifier (for e.g. a function or variable)
        ($name:ident) => {
            fn $name() {}
        };
    }
    create_useless_function!(my_useless_function);
    my_useless_function();

    // for a list of all possible desingators see https://doc.rust-lang.org/reference/macros-by-example.html

    // this prints a stringified version of an expression followed by its result
    macro_rules! print_expression {
        ($expression:expr) => {
            println!(
                "{} => {:?}",
                stringify!($expression),
                $expression
            );
        };
    }
    // remove the comments on the following lines to try it out!
    //print_expression!(2*2);
    //print_expression!(true & false);
    //print_expression!("eee");
    //print_expression!({ "this is... an expression?" });

}
