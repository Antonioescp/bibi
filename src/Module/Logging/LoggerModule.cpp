//
// Created by packa on 9/10/2024.
//

#include "LoggerModule.hpp"
#include "Logger.hpp"

namespace Bibi::Module::Logging {
    void LoggerModule::setUp(GLFWwindow* window) {
        Logger::initialize();
    }
} // Logging