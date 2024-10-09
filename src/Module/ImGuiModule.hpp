//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMGUIMODULE_HPP
#define BIBI_IMGUIMODULE_HPP

#include <spdlog/logger.h>
#include "IModule.hpp"
#include "Logging/Logger.hpp"

namespace Bibi::Module {

    class ImGuiModule : public IModule {
    public:
        void setUp() override;
        void tearDown() override;
        void run() override;

    private:
        std::shared_ptr<spdlog::logger> _logger;
    };

} // Module

#endif //BIBI_IMGUIMODULE_HPP
