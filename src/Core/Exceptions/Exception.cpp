//
// Created by packa on 10/10/2024.
//

#include "Exception.hpp"

namespace Bibi::Core::Exceptions {
    const std::source_location &Exception::location() const {
        return _location;
    }

    const std::stacktrace &Exception::stacktrace() const {
        return _stacktrace;
    }
} // Exceptions