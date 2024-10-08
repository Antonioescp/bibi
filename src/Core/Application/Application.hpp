//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_APPLICATION_HPP
#define BIBI_APPLICATION_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Bibi::Core::Application {

    class Application {
    public:
        explicit Application(GLFWwindow* window);
        void Run();
    private:
        GLFWwindow* _mainWindow;
    };

} // Application

#endif //BIBI_APPLICATION_HPP
