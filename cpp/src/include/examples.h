#ifndef EXAMPLES_H
#define EXAMPLES_H

// function definitions can be supplied with "inline"
// in header files without violating the one-definiton-rule.
// other, more traditional use of this keyword is deprecated.
inline int defined_in_header () {
    return 32;
}
// the same goes for inline variables.
// using this is best practice for global constants
// that need to be shared between multiple files!
inline constexpr float physics_constant = 6.144f;

// namespaces need to be considered here!
namespace basics     { void run_examples(); }
namespace functions  { void run_examples(); }
namespace namespaces { void run_examples(); }
namespace strings    { void run_examples(); }

#endif