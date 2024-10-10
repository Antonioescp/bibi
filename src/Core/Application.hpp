//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_APPLICATION_HPP
#define BIBI_APPLICATION_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>

#include "Module/IModule.hpp"
#include "Module/IModuleConfigurable.hpp"
#include "Module/IModuleDeconstructable.hpp"
#include "Module/IModuleRunnable.hpp"

namespace Bibi::Core {

    class Application {
    public:
        explicit Application(GLFWwindow* window);
        void addModule(std::unique_ptr<Module::IModule> module);
        void run();

        GLFWwindow* getMainWindow() { return _mainWindow; }

    private:
        GLFWwindow* _mainWindow;
        std::vector<std::unique_ptr<Module::IModule>> _modules;
        std::vector<Module::IModuleConfigurable*> _configurableModules;
        std::vector<Module::IModuleDeconstructable*> _deconstructableModules;
        std::vector<Module::IModuleRunnable*> _runnableModules;

        void setUp();
    };

} // Application

#endif //BIBI_APPLICATION_HPP
