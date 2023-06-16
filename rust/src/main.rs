/*

SETUP
- get rust: https://www.rust-lang.org/learn/get-started
- create new project: cargo new project-name

*/

// import module by filename (code in other files)
mod basics;

// entry point of the program
fn main() {

    /*
        code is split into several modules.
        each module contains a function to execute some examples.
        all of these functions will be executed below.
    */

    basics::run_basics();
}
