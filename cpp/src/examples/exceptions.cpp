#include <exception> // for std::exception
#include <stdexcept> // for std::runtime_error
#include <string>

namespace exceptions {
    // a custom exception struct!
    struct Exception {
        std::string m_message;
        Exception(std::string message) : m_message { message } {}
    };

    void run_examples() {
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
        // use just "throw" to rethrow the caught exception
        try {
            try {
                throw 0;
            } catch (...) {
          /*re*/throw;
            }
        } catch (...) {}
    }
}