//
// Created by packa on 21/10/2024.
//

#include "NameComponent.hpp"
#include "Modules/Gui/Elements/TextElement.hpp"
#include <format>

namespace Bibi::Components {
    void NameComponent::setUp() {
        _tag = "NameComponent";
    }

    std::unique_ptr<Modules::Gui::IElement> NameComponent::serializeToElement() {
        auto text{ std::format("Hello! from name component! this is {}.", _object.getTag()) };
        auto textElement = std::make_unique<Modules::Gui::Elements::TextElement>(_object.getApplication(), text);
        return textElement;
    }
} // Components
// Bibi