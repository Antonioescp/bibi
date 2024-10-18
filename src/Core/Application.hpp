//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_APPLICATION_HPP
#define BIBI_APPLICATION_HPP

#include <vector>
#include <memory>
#include <concepts>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Modules/IModule.hpp"
#include "Modules/IModuleConfigurable.hpp"
#include "Modules/IModuleDeconstructable.hpp"
#include "Modules/IModuleRunnable.hpp"

namespace Bibi::Core {

    class Application {
    public:
        explicit Application(GLFWwindow* window);
        void addModule(std::unique_ptr<Modules::IModule> module);
        void run();

        GLFWwindow* getMainWindow() { return _mainWindow; }

        template <typename TModule>
        requires std::derived_from<TModule, Modules::IModule>
        TModule* getModule() {
            for (auto& module : _modules) {
                if (auto value{ dynamic_cast<TModule*>(module.get()) }; value != nullptr) {
                    return value;
                }
            }
            return nullptr;
        }

    private:
        GLFWwindow* _mainWindow;
        std::vector<std::unique_ptr<Modules::IModule>> _modules;
        std::vector<Modules::IModuleConfigurable*> _configurableModules;
        std::vector<Modules::IModuleDeconstructable*> _deconstructableModules;
        std::vector<Modules::IModuleRunnable*> _runnableModules;

        void setUp();
    };

} // Application

#endif //BIBI_APPLICATION_HPP
