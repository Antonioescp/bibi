//
// Created by packa on 9/10/2024.
//

#include "LogModule.hpp"
#include "Logger.hpp"

namespace Bibi::Module::Logging {
    void LogModule::setUp() {
        Logger::initialize();
    }

    void LogModule::tearDown() {

    }

    void LogModule::run() {

    }
} // Logging