//
// Created by packa on 8/10/2024.
//

#include "Application.hpp"
#include <ranges>

namespace Bibi::Core {
    Application::Application(GLFWwindow *window) {
        _mainWindow = window;
    }

    void Application::run() {
        this->update();
        this->tearDown();
    }

    const std::vector<std::unique_ptr<Core::Object>> &Application::getObjects() const {
        return _objects;
    }

    void Application::addObject(std::unique_ptr<Core::Object> object) {
        _objects.push_back(std::move(object));
    }

    void Application::removeObject(const Core::Object *object) {
        auto remover = std::remove_if(_objects.begin(), _objects.end(), [&object](auto &element) {
            return element.get() == object;
        });
        _objects.erase(remover, _objects.end());
    }

    std::vector<Core::Object*> Application::getRootObjects() const {
        std::vector<Core::Object*> rootObjects{};

        for (const auto& object : _objects) {
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

            _modules.update();

            glfwSwapBuffers(_mainWindow);
        }
    }

    void Application::tearDown() {
        _modules.tearDown();
        glfwTerminate();
    }

    void Application::setUp() {
        for (auto& module: _modules.getPendingToAdd()) {
            module->setApplication(this);
        }

        _modules.setUp();
    }

    Lifecycle::DeferredCollection<Modules::IModule> &Application::getModules() {
        return _modules;
    }
} // Application