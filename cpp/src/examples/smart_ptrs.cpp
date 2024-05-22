#include <cassert>
// for smart pointers
#include <memory>

// std::unique_ptr can safely be returned by
// value as it implements move semantics.
std::unique_ptr<int> create_int(int x) {
    return std::make_unique<int>(x);
}

namespace smart_ptrs {
    void run_examples() {
        // smart pointers are wrappers for pointers to
        // dynamically allocated memory. they also take
        // care of deallocation so you don't have to!

        //// std::unique_ptr
        // unique => only owned by one object.
        // deallocates resource when going out of scope.
        std::unique_ptr<int> unique { new int { 99 } };
        // prefer initialization with std::make_unique
        // over using "new" yourself
        auto easy_unique { std::make_unique<int>(99) };
        // use conversions / overloaded operators
        assert(unique); // to check for a value
        assert(*unique == 99); // to get value
        // get from function
        auto unique_from_func { create_int(8) };
        assert(*unique_from_func == 8);

        //// std::shared_ptr
        // shared => possibly owned by multiple objects.
        // TODO

        //// std::weak_ptr
        // TODO
    }
}