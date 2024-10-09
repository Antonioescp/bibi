//
// Created by packa on 8/10/2024.
//

#include "Application.hpp"


namespace Bibi::Core::Application {
    Application::Application(GLFWwindow *window) {
        _mainWindow = window;
    }

    void Application::run() {
        while (!glfwWindowShouldClose(_mainWindow)) {
            for (auto& module : _modules) {
                module->run();
            }

            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(_mainWindow);
            glfwPollEvents();
        }

        for (auto& module : _modules) {
            module->tearDown();
        }

        glfwTerminate();
    }

    void Application::addModule(std::unique_ptr<Module::IModule> module) {
        _modules.push_back(std::move(module));
    }
} // Application