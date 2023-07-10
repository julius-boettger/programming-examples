/*

ABOUT
- i write these examples as i go through "rust by example" (https://doc.rust-lang.org/stable/rust-by-example/)
- i occasionally skip sections to work through them later
    - 1.2 Formatted print

SETUP
- get rust: https://www.rust-lang.org/learn/get-started
- create new project: cargo new project-name
- run project: cargo run

*/

// ignore some warnings for this file
#![allow(dead_code)]
#![allow(unused_macros)]
#![allow(unused_imports)]
#![allow(unreachable_code)]
#![allow(unused_variables)]
#![allow(unused_assignments)]

// import module by filename (code in other files)
mod basics;

mod enums;
mod macros;
mod traits;
mod structs;
mod control;
mod functions;

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
    functions::run_examples();
}
