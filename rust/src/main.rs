/*

SETUP
- get rust: https://www.rust-lang.org/learn/get-started
- create new project: cargo new project-name

*/

// ignore some warnings for this file
#![allow(dead_code)]
#![allow(unreachable_code)]
#![allow(unused_variables)]
#![allow(unused_assignments)]

// import module by filename (code in other files)
mod basics;
mod enums_structs_modules;

// entry point of the program
fn main() {

    /*
        code is split into several modules.
        each module contains a function to execute some examples.
        all of these functions will be executed below.
    */

    basics::run_examples();
    enums_structs_modules::run_examples();
}
