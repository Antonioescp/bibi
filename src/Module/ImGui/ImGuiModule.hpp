//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMGUIMODULE_HPP
#define BIBI_IMGUIMODULE_HPP

#include <spdlog/logger.h>
#include "Module/Logging/Logger.hpp"
#include "Module/IModuleConfigurable.hpp"
#include "Module/IModuleDeconstructable.hpp"
#include "Module/IModuleRunnable.hpp"

namespace Bibi::Module::Gui {

    class ImGuiModule : public IModuleConfigurable, public IModuleRunnable, public IModuleDeconstructable {
    public:
        void setUp(GLFWwindow* window) override;
        void run(GLFWwindow* window) override;
        void tearDown(GLFWwindow* window) override;

    private:
        std::shared_ptr<spdlog::logger> _logger;
    };

} // Module

#endif //BIBI_IMGUIMODULE_HPP
