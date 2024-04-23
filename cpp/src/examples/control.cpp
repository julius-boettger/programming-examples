namespace control {
    void run_examples() {
        //// constexpr if statements
        // require conditional to be constant expression
        constexpr int my_constant = 3;
        if constexpr (my_constant == 3) {
            // do something
        }
    }
}