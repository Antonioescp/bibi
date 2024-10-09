//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_ILOGGER_HPP
#define BIBI_ILOGGER_HPP

#include <spdlog/spdlog.h>

namespace Bibi::Module::Logging {

    class ILogger {
    public:
        virtual void log() = 0;
    };

} // Logging

#endif //BIBI_ILOGGER_HPP
