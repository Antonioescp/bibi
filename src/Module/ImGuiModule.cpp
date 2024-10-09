//
// Created by packa on 9/10/2024.
//

#include <iostream>
#include "ImGuiModule.hpp"

namespace Bibi::Module {
    void ImGuiModule::setUp() {
        _logger = Logging::Logger::getLogger("imgui");
        _logger->info("Setting up imgui");
    }

    void ImGuiModule::tearDown() {
        _logger->info("Tearing down imgui");
    }

    void ImGuiModule::run() {
        _logger->info("Running imgui");
    }
} // Module
