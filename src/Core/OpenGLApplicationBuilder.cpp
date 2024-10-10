//
// Created by packa on 8/10/2024.
//

#include <stdexcept>
#include <iostream>
#include "OpenGLApplicationBuilder.hpp"
#include "Module/IModuleConfigurable.hpp"

namespace Bibi::Core {
    IApplicationBuilder& OpenGLApplicationBuilder::setDimensions(int width, int height) {
        _width = width;
        _height = height;
        return *this;
    }

    IApplicationBuilder& OpenGLApplicationBuilder::setTitle(std::string title) {
        _title = std::move(title);
        return *this;
    }

    Application OpenGLApplicationBuilder::build() {
        auto success{ glfwInit() };
        if (success == GLFW_FALSE) {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        // Estableciendo version de OpenGL (4.6) con perfil CORE
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        auto window{ glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr) };
        if (window == nullptr) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            throw std::runtime_error("Failed to initialize GLAD");
        }

        glViewport(0, 0, _width, _height);

        Application app{ window };

        for (auto& module: _modules) {
            app.addModule(std::move(module));
        }

        _modules.clear();

        return app;
    }

    IApplicationBuilder& OpenGLApplicationBuilder::addModule(std::unique_ptr<Module::IModule> module) {
        _modules.push_back(std::move(module));
        return *this;
    }

} // Application