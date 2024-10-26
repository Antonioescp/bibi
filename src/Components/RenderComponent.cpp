//
// Created by packa on 25/10/2024.
//

#include "RenderComponent.hpp"
#include "Modules/Gui/Element.hpp"

namespace Bibi::Components {
    void RenderComponent::setUp() {
        this->setName("Render");
    }

    std::unique_ptr<Modules::Gui::IElement> RenderComponent::serializeToElement() {
        auto container{ std::make_unique<Modules::Gui::Element>() };

        return container;
    }
} // Components
