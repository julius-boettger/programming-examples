#ifndef EXAMPLES_H
#define EXAMPLES_H

// function definitions can be supplied with "inline"
// in header files without violating the one-definiton-rule.
// other, more traditional use of this keyword is deprecated.
inline int defined_in_header () {
    return 32;
}

// namespaces need to be considered here!
namespace basics    { void run_examples(); }
namespace functions { void run_examples(); }

#endif