//
// Created by packa on 8/10/2024.
//

#include "Application.hpp"

namespace Bibi::Core {
    Application::Application(GLFWwindow *window) {
        _mainWindow = window;
    }

    void Application::run() {
        this->update();
        this->tearDown();
    }

    std::vector<Core::Object*> Application::getRootObjects() {
        std::vector<Core::Object*> rootObjects{};

        for (auto& object : _objects) {
            if (object->getParent() == nullptr) {
                rootObjects.push_back(object.get());
            }
        }

        for (auto& object : _objects.getPendingToAdd()) {
            if (object->getParent() == nullptr) {
                rootObjects.push_back(object.get());
            }
        }

        return rootObjects;
    }

    void Application::update() {
        while (!glfwWindowShouldClose(_mainWindow)) {
            glfwPollEvents();
            glClear(GL_COLOR_BUFFER_BIT);

            _objects.update();
            _modules.update();

            glfwSwapBuffers(_mainWindow);
        }
    }

    void Application::tearDown() {
        _modules.tearDown();
        _objects.tearDown();
        glfwTerminate();
    }

    void Application::setUp() {
        for (auto& module: _modules.getPendingToAdd()) {
            module->setApplication(this);
        }

        _modules.setUp();
        _objects.setUp();
    }

    Lifecycle::DeferredCollection<Modules::IModule> &Application::getModules() {
        return _modules;
    }

    Lifecycle::DeferredCollection<Object> &Application::getObjects() {
        return _objects;
    }
} // Application