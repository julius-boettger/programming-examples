namespace control {
    void run_examples() {
        //// range-based for loop
        int array[] {1, 2, 3};
        for (int i : array) {
            // do something
        }

        //// constexpr if statements
        // require conditional to be constant expression
        constexpr int my_constant = 3;
        if constexpr (my_constant == 3) {
            // do something
        }

        //// intentional switch fallthrough
        switch (0)
        {
        case 0:
            // attribute to indicate intentional fallthrough
            // not necessary, but good practice
            [[fallthrough]]; // <-- also mind the ";" ("null statement")
        default:
            break;
        }
    }
}