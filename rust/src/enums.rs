// this enum is not in the examples function on purpose!
enum SimpleEnum { Cool }

/// examples for enums
pub fn run_examples() {
    // an enum is a type which can only be one of a few different options
    // each option is a struct (unit, tuple or classic)
    enum Stuff {
        UnitType,
        TupleType(i32, i32),
        StructType { name: String }
    }

    // each option is assigned a numeric value ("discriminant").
    // the following is the default
    enum Numbers {
        Zero, // 0
        One,  // 1
        Two   // 2
    }
    // the discriminant can be retreived with casting
    assert_eq!(Numbers::Zero as i32, 0);

    // discriminants can also be assigned to options explicitly
    enum FavouriteNumbers {
        First = 12,
        Second = 2
    }
    assert_eq!(FavouriteNumbers::First as i32, 12);

    // an enum can also be generic
    enum Tuples<T> {
        Pair(T, T),
        Triplet(T, T, T)
    }
    let triplet = Tuples::Triplet(1, 2, 3);

    // type aliases can shorten a long enum name
    enum EnumWithVeryLongAndSpecificName { OnlyOption }
    type LongEnum = EnumWithVeryLongAndSpecificName;
    let option = LongEnum::OnlyOption;

    // this can lead to pretty long statements
    let cool_var = SimpleEnum::Cool;
    // "use" values of an enum in this scope to make them more easily accessible
    // but this is bad practice! it can lead to some unexpected behaviour with match expressions
    use SimpleEnum::*;
    let cool_var = Cool;
    // this should be done instead:
    use SimpleEnum as S;
    let cool_var = S::Cool;
    // it is also possible to just "use" specific elements
    use Numbers::{Zero, One};
}
