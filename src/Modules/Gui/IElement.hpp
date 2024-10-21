//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IELEMENT_HPP
#define BIBI_IELEMENT_HPP

#include <string>
#include <memory>
#include <vector>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "Core/Application.hpp"

namespace Bibi::Modules::Gui {
class IElement : public Core::Lifecycle::ILifecycleAware {
    public:
        ~IElement() override = default;
        virtual void addElement(std::unique_ptr<IElement> element) = 0;
        virtual void removeElement(IElement* element) = 0;
        virtual void removeElements(std::string tag) = 0;
        virtual void clearElements() = 0;
        virtual std::vector<std::unique_ptr<IElement>>& getElements() = 0;
        virtual void setTag(std::string tag) = 0;
        virtual std::string getTag() = 0;
        virtual void setParent(IElement* parent) = 0;
        virtual IElement* getParent() = 0;
        virtual Core::Application * getApplication() = 0;
        virtual void setApplication(Core::Application *application) = 0;
        virtual IElement* getChildByTag(std::string_view tag) = 0;
    };
} // Modules

#endif //BIBI_IELEMENT_HPP
