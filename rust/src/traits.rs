/// examples for associated functions/methods and traits
pub fn run_examples() {

    // classic struct (see structs.rs)
    struct Person { name: String, age: u8 }
    // this "implementation block" associates functions and methods with a type
    // in this case the earlier defined struct, could also be enum
    impl Person {
        // this is an associated function. the "new"-function is
        // often treated like a constructor in other languages.
        // functions can be called like Person::new (without an instance)
        fn new(name: String, age: u8) -> Person {
            Person { name, age }
        }

        // this is an associated method (because it takes &self as the first argument).
        // methods can be called like person.increase_age() (with an instance)
        fn increase_age(&mut self) -> () {
            self.age += 1;
        }

        // another example function
        fn function() {}
    }

    // instantiate a new person
    let mut person = Person::new(
        String::from("peter"),
        58
    );
    // call the defined method with "."
    person.increase_age();
    // call another function with "::"
    Person::function();

    //// traits

    // a gecko struct with an associated function
    struct Gecko { name: String }
    impl Gecko {
        fn new(name: String) -> Gecko {
            Gecko { name }
        }
    }

    // a trait is a collection of methods that can be implemented by a type
    trait Pet {
        // a function doesn't need to have a body
        fn name(&self) -> &String;
        // but it can have one to provide a default implementation
        fn noise() -> String {
            String::from("*weird noise*")
        }
    }
    // Gecko needs to implement all of Pet's methods in this implementation block
    impl Pet for Gecko {
        fn name(&self) -> &String {
            &self.name
        }

        fn noise() -> String {
            String::from("...")
        }
    }

    //// the derive attribute
    // rust provides basic implementation for some traits
    #[derive(
        //// comparison traits
        // makes equality comparisons possible.
        //     for structs: equality of all fields
        //     for enums: equality of variant and all fields
        // a == b, a != b become available.
        PartialEq,
        // PartialEq, but some additional logic is implied
        // a == b => b == a, ...
        Eq,
        // makes order comparisons possible.
        //     for structs: lexicographical comparison of members from top-to-bottom
        //     for enums: comparison of discriminants
        // a < b, a <= b, a > b, a >= b become available.
        PartialOrd, 
        // PartialOrd, but... i don't get the difference. use this one?
        Ord,

        // changes move-semantics to copy-semantics, where a bit-wise copy is executed
        // also requires Clone
        Copy,
        // a more generic version of Copy where you can run
        // some code to get a duplicate of an instance
        Clone,
        // makes type able to be hashed by a Hasher
        Hash,
        // provides Type::default(), which initializes all struct fields with default values
        Default, 
        // allows {:?} debug formatting of type
        Debug
    )]
    struct DoItAll;

}
