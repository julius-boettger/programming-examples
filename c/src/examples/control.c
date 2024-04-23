#include <stdbool.h>
#include <stdio.h>

void example_control () {
    //// notes about conditions
    // conditions are only false if their decimal value is 0
    // meaning everything else is "true"!
    if ( 0) { /* will NOT be executed. */ }
    if (-1) { /* will     be executed! */ }
    if ( 1) { /* will     be executed! */ }
    if (32) { /* will     be executed! */ }

    //// if / else statement
    if (true && (true || !false)) {
        // run some code
    } else if (false) {
        // more
    } else {
        // even more
    }

    //// ternary operator
    int result = true ? 1 : 0;

    //// switch statement
    // best practice wherever possible
    switch (0) {
    // multiple cases are possible!
    case 1:
    case 2:
        printf("one or two...?\n");
        break;
    case 3:
        printf("three!\n");
        // no "break;"! "fall through"
        // => run everything until next "break;"
    default: // if no match is found
        // do nothing :)
        break;
    }

    //// while
    while (true) {
        // do something
        break;
        continue;
    }
    //// do while
    do {
        // do something
        break;
        continue;
    } while (true);
    //// for
    for (int i = 0; i < 10; i++) {
        // do something
        break;
        continue;
    }

    //// goto
    // you should probably never use this, but it exists.
    // jump to label
    goto gotolabel;
    // label
gotolabel:
    // do something
    int four = 2 + 2;
}