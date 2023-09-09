/// examples for asynchronous programming using async/await
pub fn run_examples() {
    // an async function or block returns a future
    async fn get_value() -> u8 { 3 }
    let value_future = get_value();
    // block current thread until future has run to completion
    // (helper function from crate "futures", see Cargo.toml)
    let value = futures::executor::block_on(value_future);
    // async blocks are also possible. they can capture variables like closures
    // this references captured variables
    let      block_future = async      { 3 };
    // this moves captured variables, like a move closure
    let move_block_future = async move { 3 };

    // inside of an async function it's possible
    // to await the result of another:
    async fn call_api() -> u8 {
        // await result of async function get_value() before moving on
        let value = get_value().await;
        value * 2
    }

    async fn join_example() {
        // await multiple async functions concurrently
        futures::join!(
            call_api(),
            get_value()
        );
        // now everything ran to completion!
    }
}