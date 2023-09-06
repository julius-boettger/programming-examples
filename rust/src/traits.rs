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
        fn name(&self) -> String;
        // but it can have one to provide a default implementation
        fn noise() -> String {
            String::from("*weird noise*")
        }
    }

    // Gecko needs to implement all of Pet's methods in this implementation block
    impl Pet for Gecko {
        fn name(&self) -> String {
            self.name.clone()
        }

        fn noise() -> String {
            String::from("...")
        }
    }

    // another trait
    trait Dangerous {
        fn get_danger_level() -> u8;
    }

    // a subtrait, which is a combination of at least one supertrait
    // implementing a subtrait also requires implementing all supertraits!
    trait DangerousPet: Dangerous + Pet {
        fn is_good_pet() -> bool;
    }

    // a komodo dragon is a dangerous pet
    struct KomodoDragon;
    // implement subtrait
    impl DangerousPet for KomodoDragon {
        fn is_good_pet() -> bool { false }
    }
    // implement its supertraits
    impl Dangerous for KomodoDragon {
        fn get_danger_level() -> u8 { 255 }
    }
    impl Pet for KomodoDragon {
        fn name(&self) -> String {
            String::from("(unnamed komodo dragon)")
        }
    }

    //// working with overlapping traits
    // it's possible for a type to implement functions with the same name from different traits
    struct Confusing;
    trait Trait1 { fn get_string() -> String { "from Trait1".to_owned() } }
    trait Trait2 { fn get_string() -> String { "from Trait2".to_owned() } }
    impl Trait1 for Confusing {}
    impl Trait2 for Confusing {}
    // decice which implementation to use through fully qualified syntax
    assert_eq!(<Confusing as Trait1>::get_string(), "from Trait1");
    assert_eq!(<Confusing as Trait2>::get_string(), "from Trait2");

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
        // a more generic version of Copy that implements
        // clone() to get a duplicate of an instance
        Clone,
        // makes type able to be hashed by a Hasher
        Hash,
        // provides Type::default(), which initializes all struct fields with default values
        Default, 
        // allows {:?} debug formatting of type
        Debug
    )]
    struct DoItAll;

    // Drop trait: only method drop() is called when an object goes out of scope
    struct Droppable;
    impl Drop for Droppable {
        fn drop(&mut self) {
            println!("a Droppable was dropped!");
        }
    }

    // Iterator trait: only method into_iter()
    struct RangeWrapper(std::ops::Range<i32>);
    impl Iterator for RangeWrapper {
        type Item = i32; // type of iterating items
        fn next(&mut self) -> Option<Self::Item> {
            self.0.next()
        }
    }
    // x = 1, 2, 3, 4
    for x in RangeWrapper(0..5).into_iter() {}
}
