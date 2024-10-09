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

namespace Bibi::Core::Application {

    class Application {
    public:
        explicit Application(GLFWwindow* window);
        void addModule(std::unique_ptr<Module::IModule> module);
        void run();
    private:
        GLFWwindow* _mainWindow;
        std::vector<std::unique_ptr<Module::IModule>> _modules;
    };

} // Application

#endif //BIBI_APPLICATION_HPP
