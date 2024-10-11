//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IELEMENT_HPP
#define BIBI_IELEMENT_HPP

#include <GLFW/glfw3.h>

namespace Bibi::Module::Gui {

    class IElement {
    public:
        explicit IElement(GLFWwindow* window) : _window{window} {};
        virtual ~IElement() = default;
        virtual void render() = 0;
        virtual void setUp() = 0;

    protected:
        GLFWwindow* _window;
    };

} // Module

#endif //BIBI_IELEMENT_HPP
