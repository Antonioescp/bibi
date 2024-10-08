//
// Created by packa on 8/10/2024.
//

#include "Application.hpp"


namespace Bibi::Core::Application {
    Application::Application(GLFWwindow *window) {
        _mainWindow = window;
    }

    void Application::Run() {
        while (!glfwWindowShouldClose(_mainWindow)) {
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(_mainWindow);
            glfwPollEvents();
        }

        glfwTerminate();
    }
} // Application