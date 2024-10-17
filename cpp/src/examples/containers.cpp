#include <array>  // std::array
#include <vector> // std::vector

#include <cassert>

namespace containers {
    void run_examples() {
        // containers provide storage for unnamed objects (elements),
        // e.g. arrays or strings (containers for characters).
        // see all containers here: https://en.cppreference.com/w/cpp/container

        ////// arrays
        //// c-style array
        // exists for compatability, but should be avoided
        int c_style_array[] { 1, 2, 3 };
        // get (unsigned) size of any kind of array, including c-style!
        assert(std::size(c_style_array) == 3);
        // get signed size (very useful!) 
        assert(std::ssize(c_style_array) == 3);

        //// std::array
        // c-style array, but better!
        // fixed size  vvv
        std::array<int, 3> std_array { 1, 2, 3 };
        assert(std_array.size() == 3);
        // access returns a reference
        assert(std_array[0] == 1);
        // access with bounds checking: throws catchable
        // exception if out of bounds. slower but safer,
        // yet rarely used, just check the index yourself.
        assert(std_array.at(0) == 1);
        // can be constexpr (or const)
        constexpr std::array<int, 1> const_array { 0 };

        //// std::vector
        // dynamic array (variable size!)
        std::vector<int> vector { 1, 2, 3 };
        // element type can be omitted
        std::vector auto_vector { 'x' };
        // initialize with 10 zero-initialized ints
        std::vector<int> sized_vector(10);
        assert(sized_vector.size() == 10);
        // can be const, but not constexpr
        const std::vector const_vector { true };
        // can be resized manually
        vector.resize(10); // grow, fill with zeros
        assert(vector.size() == 10);
        vector.resize(1); // shrink, discard elements
        assert(vector.size() == 1);
        vector.shrink_to_fit(); // ask runtime to free unused memory
        // allocate memory for more elements without initializing it
        vector.reserve(3);
        // also has stack capabilities
        vector.push_back(5);
        assert(vector.size() == 2);
        // prefer emplace_back over push_back when pushing temporary objects
        // for efficiency. this can even access explicit constructors!
        vector.emplace_back(10);
        // bool vectors have a special implementation that
        // you likely want to avoid becaus it's big and slow
        std::vector<bool> bool_vector { true, false };
        // can also be returned safely as it implements move semantics!
    }
}