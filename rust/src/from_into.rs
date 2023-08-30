/// examples for From, Into, TryFrom and TryInto conversions
pub fn run_examples() {
    // u8 to char conversion using from()
    let my_char_from: char = char::from(15u8);
    // u8 to char conversion using into()
    let my_char_into: char = (15u8).into();
    assert_eq!(my_char_from, my_char_into);

    //// from() and into() can also be written for your own structs/enums

    // example struct
    #[derive(Debug, Clone)]
    struct NumberWrapper { value: u128 }

    // implementing the From trait makes from() and into() (!) available
    // into() is automatically derived from the definition of from()
    impl From<u128> for NumberWrapper {
        fn from(item: u128) -> Self {
            NumberWrapper { value: item }
        }
    }
    impl From<NumberWrapper> for u128 {
        fn from(item: NumberWrapper) -> Self {
            item.value
        }
    }

    // it is also possible to implement the Into trait, which only makes
    // into() available. this may lead to conflicting definitions if the
    // From trait also provides a definition for into()
    /*impl Into<u128> for NumberWrapper {
        fn into(self) -> u128 {
            self.value
        }
    }
    impl Into<NumberWrapper> for u128 {
        fn into(self) -> NumberWrapper {
            NumberWrapper { value: self }
        }
    }*/

    // test out from() and into()
    let num = 3u128;
    let wrapper = NumberWrapper {value: num.clone()};
    let _ = NumberWrapper::from(    num.clone());
    let _ =          u128::from(wrapper.clone());
    let _: NumberWrapper = (    num.clone()).into();
    let _:          u128 = (wrapper.clone()).into();
}
