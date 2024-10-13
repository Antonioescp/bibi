//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IELEMENT_HPP
#define BIBI_IELEMENT_HPP

#include <string>
#include <memory>
#include <vector>
#include <GLFW/glfw3.h>

namespace Bibi::Module::Gui {
    class IElement {
    public:
        virtual ~IElement() = default;
        virtual void render() = 0;
        virtual void setUp() = 0;
        virtual void tearDown() = 0;
        virtual void addElement(std::unique_ptr<IElement> element) = 0;
        virtual void removeElement(std::string tag) = 0;
        virtual void clearElements() = 0;
        virtual std::vector<std::unique_ptr<IElement>>& getElements() = 0;
        virtual void setTag(std::string tag) = 0;
        virtual std::string getTag() = 0;
        virtual void setParent(IElement* parent) = 0;
        virtual IElement* getParent() = 0;
        virtual GLFWwindow* getWindow() = 0;
        virtual void setWindow(GLFWwindow* window) = 0;
        virtual IElement* getChildByTag(std::string_view tag) = 0;
    };
} // Module

#endif //BIBI_IELEMENT_HPP
