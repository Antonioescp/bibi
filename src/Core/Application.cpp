//
// Created by packa on 8/10/2024.
//

#include "Application.hpp"
#include <ranges>

namespace Bibi::Core {
    Application::Application(GLFWwindow *window) {
        _mainWindow = window;
    }

    void Application::addModule(std::unique_ptr<Modules::IModule> module) {
        auto configurableModule{ dynamic_cast<Modules::IModuleConfigurable*>(module.get()) };
        if (configurableModule != nullptr) {
            _configurableModules.push_back(configurableModule);
        }

        auto deconstructableModule{ dynamic_cast<Modules::IModuleDeconstructable*>(module.get()) };
        if (deconstructableModule != nullptr) {
            _deconstructableModules.push_back(deconstructableModule);
        }

        auto runnableModule{ dynamic_cast<Modules::IModuleRunnable*>(module.get()) };
        if (runnableModule != nullptr) {
            _runnableModules.push_back(runnableModule);
        }

        _modules.push_back(std::move(module));
    }

    void Application::setUp() {
        for (auto module : _configurableModules) {
            module->setUp();
        }
    }

    void Application::run() {
        this->setUp();

        while (!glfwWindowShouldClose(_mainWindow)) {
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT);
            for (auto& module : _runnableModules) {
                module->run();
            }

            glfwSwapBuffers(_mainWindow);
        }

        auto reversedModules = std::ranges::views::reverse(_deconstructableModules);
        for (auto module : reversedModules) {
            module->tearDown();
        }

        glfwTerminate();
    }
} // Application