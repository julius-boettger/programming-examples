namespace basics {
    void run_examples() {
        //// types of initialization
        int default_init;     // => garbage value
        int  direct_init(2);  // confusing, looks like function call
        int    copy_init = 1; // a.k.a. "c-style", copy from right to left
        // list/uniform/brace initialization methods
        // are usually preferred!
        int       value_init{ };    // best practice, uses default value like 0
        int direct_list_init{3};    // best practice!
        int   copy_list_init = {4}; // less common/preferred than the other two
        // initializing multiple variables of the same type like this is possible!
        int x{1}, y(2), z = 3;
    }
}