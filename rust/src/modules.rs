const MODULE_CONSTANT: () = ();
/// examples for modules
pub fn run_examples() {
    // a module is a collection of items like functions, structs, traits, and even other modules
    // all items are private by default => access is only possible inside the modules scope
    // use "pub" to make an item public
    // each file (like this one) is also a module that can be imported using its filename (see main.rs)
    mod my_module {
        // private constant
        const MY_CONST: u8 = 10;
        // public stuff
        pub struct MyStruct {
            // structs can even declare fields as private or public.
            // the same rules as for modules apply.
            pub public_field: (),
            private_field: ()
        }
        pub fn get_instance() -> MyStruct {
            MyStruct {
                public_field: (),
                private_field: ()
            }
        }
        // nested module
        pub mod nested {
            // only public in parent module
            pub(super)             struct A;
            // only public in this crate
            pub(crate)             struct B;
            // only public in a specific module
            pub(in crate::modules) struct C;
        }
    }
    // call something from a module
    my_module::get_instance();
    // the current crate is basically the current project
    // that will be compiled into a single binary.
    // it is globally accessible as the outermost module.
    crate::functions::run_examples();
    // super refers to the parent module. here: crate
    super::functions::run_examples();
    // self refers to the current module.
    // like in Java, it is usually not needed, but can make code easier to understand.
    let _ = self::MODULE_CONSTANT;
    let _ =       MODULE_CONSTANT;
}