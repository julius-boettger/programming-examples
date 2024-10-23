#include <exception> // for std::exception
#include <stdexcept> // for std::runtime_error
#include <string>

namespace exceptions {
    // a custom exception struct!
    struct Exception {
        std::string m_message;
        Exception(std::string message) : m_message { message } {}
    };

    // noexcept
    // promise not to throw exceptions. this is not enforced by the
    // compiler, it's more of a hint. only use it when you are sure that
    // you don't call other functions that could possibly throw exceptions.
    void nothing_bad() noexcept {}

    // "function try blocks" can replace normal function bodies
    // pretty much only useful for constructors with member
    // initialization lists, because they can catch errors that 
    void function_try() try {
        throw 0;
    } catch (...) {
        // don't let control reach the end of a function catch block!
        // behavior can be counter intuitive and depends on the context
        // prefer to explicitly return or (re)throw
        return;
    }

    void run_examples() {
        nothing_bad();
        function_try();

        // throw simple literals (catch by value)
        try { throw      -1; } catch (        int exception) {}
        try { throw "error"; } catch (const char* exception) {}

        // throw classes/structs (catch by reference)
        try {
            throw Exception("from struct");
        } catch (const Exception& exception) {
            // do something...
        }

        // std::exception is the base class all standard
        // library exception classes are derived from
        std::exception std_exception;
        // a commonly used one is std::runtime_error
        try {
            throw std::runtime_error("error!");
        } catch (const std::exception& exception) {
            // do something...
        }

        //// other useful tricks
        // "catch-all handler"
        try { throw nullptr; } catch (...) {}

        // check at compile time if an expression will throw an exception
        static_assert( noexcept(          0     )); // no exception
        static_assert(!noexcept([]{ throw 0; }())); // lambda that throws exception

        // use just "throw" to rethrow the caught exception
        try {
            try {
                throw 0;
            } catch (...) {
          /*re*/throw;
            }
        } catch (...) {}

        // std::move_if_noexcept
        // safer version of std::move with extra compile-time checks.
        // return movable rvalue if object has noexcept move constructor,
        // otherwise return a copyable lvalue. std::move will always
        // attempt the move, possibly throwing exceptions.
        int a { 1 };
        int b { std::move_if_noexcept(a) };
    }
}