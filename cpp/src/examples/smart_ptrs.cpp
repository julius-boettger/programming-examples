#include <cassert>
// for smart pointers
#include <memory>

// to produce a cyclical reference later
struct Resource {
    std::shared_ptr<Resource> ptr {};
};

// std::unique_ptr can safely be returned by
// value as it implements move semantics.
std::unique_ptr<int> create_int(int x) {
    return std::make_unique<int>(x);
}

namespace smart_ptrs {
    void run_examples() {
        // smart pointers are wrappers for pointers to
        // dynamically allocated objects. they also take
        // care of deallocation so you don't have to!

        //// std::unique_ptr
        // only owner of its object.
        // deallocates object when going out of scope.
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
        // one of many owners of its object.
        // deallocates object when last owner goes out of scope
        // (meaning that the interal reference count is 0)
        int* obj { new int { 6 } };
        std::shared_ptr<int> shared1 { obj };
        // construct more with existing shared_ptr
        std::shared_ptr<int> shared2 { shared1 };
        // std::make_shared
        // (can't reference an existing object, allocates its own)
        auto easy_shared1 { std::make_shared<int>(5) };
        auto easy_shared2 { easy_shared1 };

        // be aware of cyclical references!
        // they prevent the object from being freed at runtime.
        Resource cyclical_ref {};
        // store shared_ptr to self in self:
        cyclical_ref.ptr = std::make_shared<Resource>(cyclical_ref);

        //// std::weak_ptr
        // avoids shared_ptr's cyclical reference issues by
        // not being an owner of its object, but a viewer!
        // the viewed object will not be deallocated
        // when a weak_ptr goes out of scope.
        std::weak_ptr<int> view { shared1 };
        // weak pointers are not directly accessible.
        // you need to lock them first (convert to shared_ptr)
        int contained_value { *view.lock() };
        // you can also check if the viewed object is still alive
        // (using reference count of underlying shared_ptr)
        assert(!view.expired());
    }
}