//
// Created by packa on 20/10/2024.
//

#ifndef BIBI_COMPONENT_HPP
#define BIBI_COMPONENT_HPP

#include <string>
#include <memory>
#include "Core/Lifecycle/ILifecycleAware.hpp"
#include "Modules/Gui/IElement.hpp"

namespace Bibi::Core {
    class Object;
}

namespace Bibi::Core {

    class Component : public virtual Lifecycle::ILifecycleAware {
    public:
        explicit Component(Object &object);
        ~Component() override = default;

        void setUp() override {}
        void update() override {}
        void tearDown() override {}

        [[nodiscard]] std::string getTag() const;
        void setTag(std::string tag);

        virtual std::unique_ptr<Modules::Gui::IElement> serializeToElement() = 0;
    protected:
        Object &_object;
        std::string _tag;
    };

} // Core

#endif //BIBI_COMPONENT_HPP
