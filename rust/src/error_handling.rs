/// examples for error handling
pub fn run_examples() {
    //// panic
    // if something does wrong and the program exits, we say: the program panicked
    // you can let the program panic on purpose with some macros:
    //panic!();
    //todo!();
    //unimplemented!();

    //// Option can be Some(value) or None
    // you can think of None as null in other languages, but with better checking
    let option: Option<i32> = Some(3);
    // get contained value or panic if None
    let contained_value = option.unwrap();
    // get contained value or panic with message if None
    let contained_value = option.expect("something went wrong?");
    // get contained value or a default if None
    let contained_value = option.unwrap_or(0);
    // map an options value (if present, otherwise do nothing)
    let mapped = option.map(|value: i32| value * 2);
    // and_then() is sometimes better than map(), as it might avoid an extra Option wrap
    // this is equivalent to map().flatten()
    let better_mapped = mapped.and_then(|value: i32| Some(value *2));

    //// Result can be Ok(value) or Err(error)
    // value and error have the supplied types
    let mut result: Result<i32, &str> = Err("something went wrong?");
    result = Ok(12);
    // get ok as option
    let ok_option = result.ok();
    // get err as option
    let err_option = result.err();
    // most functions from Option also work
    let contained_value = result.unwrap_or(0);
    // using custom result type aliases can be helpful
    type ParseIntResult<T> = Result<T, std::num::ParseIntError>;

    //// the ? operator
    // when working with multiple options/results in a fucntion which returns one you can use the ? operator
    // as a shortcut to either extract the success value or immediately return the failure value
    fn get_result() -> Result<String, ()> {
        // result that was generated earlier in this function
        let earlier_result: Result<String, ()> = Ok("this is fine".to_owned());
        // extract String value or return unit type error
        let value = earlier_result?;
        // if we're here: extraction was successful!
        println!("extraction successful!");
        Ok(value)
    }
    // similar example with options
    fn get_option() -> Option<String> {
        // option that was generated earlier in this function
        let earlier_option: Option<String> = Some("this is fine".to_owned());
        // extract String value or return None
        let value = earlier_option?;
        // if we're here: extraction was successful!
        println!("extraction successful!");
        Some(value)
    }
}