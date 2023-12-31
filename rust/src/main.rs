/*

ABOUT
- i write these examples as i go through "rust by example" (https://doc.rust-lang.org/stable/rust-by-example/)

SETUP
- get rust: https://www.rust-lang.org/learn/get-started
- create new project: cargo new project-name
- run project: cargo run
- run tests in project: cargo test

TODO (rust by example chapters)
- 14 generics
- 18.3.4 or, or_else, ...
- 20 std misc
- async https://rust-lang.github.io/async-book

*/

// ignore some warnings for this crate (by using an attribute)
// the ! means "for this crate", without it it's "for this module/item"
#![allow(
    dead_code,
    unused_macros,
    unused_imports,
    unreachable_code,
    unused_variables,
    unused_assignments,
    irrefutable_let_patterns
)]

// import code in other files as modules
mod basics;

mod enums;
mod macros;
mod traits;
mod structs;
mod control;
mod modules;
mod r#async; // escape module name because it's also a keyword
mod functions;
mod from_into;
mod collections;
mod concurrency;
mod error_handling;

// entry point of the program
fn main() {

    /*
        code is split into several modules.
        each module contains a function to execute some examples.
        all of these functions will be executed below.
    */

    basics::run_examples();

    enums::run_examples();
    macros::run_examples();
    traits::run_examples();
    structs::run_examples();
    control::run_examples();
    modules::run_examples();
    r#async::run_examples();
    functions::run_examples();
    from_into::run_examples();
    collections::run_examples();
    concurrency::run_examples();
    error_handling::run_examples();
}
