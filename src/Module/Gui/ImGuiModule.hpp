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
#include "Module/Gui/IElement.hpp"

namespace Bibi::Module::Gui {

    class ImGuiModule : public IModuleConfigurable, public IModuleRunnable, public IModuleDeconstructable {
    public:
        void setUp(GLFWwindow* window) override;
        void run(GLFWwindow* window) override;
        void tearDown(GLFWwindow* window) override;
        void addElement(std::unique_ptr<IElement> element);

    private:
        std::shared_ptr<spdlog::logger> _logger;
        std::vector<std::unique_ptr<IElement>> _elements;

        void initializeImGui(GLFWwindow* window);
        void registerElements(GLFWwindow* window);
    };

} // Module

#endif //BIBI_IMGUIMODULE_HPP
