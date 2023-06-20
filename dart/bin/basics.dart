// the following is a doc-comment:
/// examples for basic syntax and concepts
void basicExamples() {
    // print hello world to the console
    print("Hello World!");

    //// variables
    // the type of a variable will be inferred when using "var":
    var firstVariable = 0;
    // the type can also be annotated manually:
    int secondVariable = firstVariable;
    // a questionmark allows a variable to be null
    int? nullable = null;

    //// statements
    if (true) {
        // do something
    } else if (false) {
        // do something else
    }

    //// loops
    for (int i = 1; i < 10; i++) {
        // do something
    }

    // final is a good practice and makes the iterating variable immutable
    for (final number in [1, 2, 3]) {
        // the following is not allowed!
        // number = 1;
    }

    while (false) {
        // do nothing!
    }
}
