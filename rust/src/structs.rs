/// examples for structs
pub fn run_examples() {
    //// unit struct: has no fields, apparently useful for generics?
    struct AbsoluteUnit;
    let absolute_unit = AbsoluteUnit; // why?

    //// tuple struct: basically tuple type with a name
    struct IntegerPair(i32, i32);
    let integer_pair = IntegerPair(0, 1);
    // deconstruct
    let IntegerPair(first_int, _) = integer_pair;
    assert_eq!(first_int, integer_pair.0);

    //// classic struct: has named fields
    struct Cat {
        name: String,
        age: u8
    }
    // instantiate a cat
    let cat = Cat {
        name: String::from("the cat"),
        age: 3
    };
    // deconstruct
    let Cat { name: _, age: cat_age } = cat;
    assert_eq!(cat_age, cat.age)
}
