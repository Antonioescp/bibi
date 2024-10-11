//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_EXCEPTION_HPP
#define BIBI_EXCEPTION_HPP

#include <exception>
#include <stacktrace>
#include <source_location>
#include <utility>

namespace Bibi::Core::Exceptions {

    class Exception : public std::exception {
    public:
        explicit Exception(
                const char *message,
                std::stacktrace stacktrace = std::stacktrace::current(),
                std::source_location location = std::source_location::current())
                : std::exception(message), _stacktrace(std::move(stacktrace)), _location(location) {
        }

        [[nodiscard]] const std::stacktrace &stacktrace() const;
        [[nodiscard]] const std::source_location &location() const;

    private:
        std::stacktrace _stacktrace;
        std::source_location _location;
    };

} // Exceptions

#endif //BIBI_EXCEPTION_HPP
