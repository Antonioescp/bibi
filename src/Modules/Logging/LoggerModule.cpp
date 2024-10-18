//
// Created by packa on 9/10/2024.
//

#include "LoggerModule.hpp"
#include "Logger.hpp"

namespace Bibi::Modules::Logging {
    void LoggerModule::setUp() {
        Logger::initialize();
    }
} // Logging