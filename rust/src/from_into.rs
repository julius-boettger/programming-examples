/// examples for From, Into, TryFrom and TryInto conversions
pub fn run_examples() {
    // u8 to char conversion using from()
    let my_char_from: char = char::from(15u8);
    // u8 to char conversion using into()
    let my_char_into: char = (15u8).into();
    assert_eq!(my_char_from, my_char_into);

    //// from() and into() can also be written for your own structs/enums

    // example struct
    #[derive(Debug, Clone, PartialEq)]
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

    // try_from() and try_into() return results because the conversion
    // can fail in this (bad) example the error is of type Infallible,
    // which means an error is impossible.
    use std::convert::Infallible;
    let my_string_from: Result<String, Infallible> = String::try_from('x');
    let my_string_into: Result<String, Infallible> = 'x'.try_into();

    // TryFrom and TryInto are also traits
    impl TryFrom<i64> for NumberWrapper {
        type Error = (); // this is necessary!
        /// conversion only works if item is >= 0
        fn try_from(item: i64) -> Result<Self, Self::Error> {
            match item {
                0.. => Ok(NumberWrapper { value: (item as u128) }),
                _ => Err(())
            }
        }
    }

    // into string: NumberWrapper => string
    // generates to_string() and enables display formatting
    use std::fmt;
    impl fmt::Display for NumberWrapper {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "{}", self.value)
        }
    }
    // from string: string => NumberWrapper
    use std::str;
    impl str::FromStr for NumberWrapper {
        type Err = (); // this is necessary!
        fn from_str(s: &str) -> Result<Self, Self::Err> {
            // try to parse string to u128 and return Result based on success
            match s.parse::<u128>() {
                Ok(value) => Ok(NumberWrapper { value }),
                Err(_) => Err(())
            }
        }
    }
    // when using display formatting, calling to_string() is obsolete
    assert_eq!(
        format!("{}", wrapper),
        format!("{}", wrapper.to_string())
    );
    // parse from string
    assert_eq!( "5".parse::<NumberWrapper>(), Ok(NumberWrapper { value: 5 }));
    assert_eq!("-1".parse::<NumberWrapper>(), Err(()));
}
