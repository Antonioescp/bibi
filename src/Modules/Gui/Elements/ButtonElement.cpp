//
// Created by packa on 19/10/2024.
//

#include <imgui.h>
#include "ButtonElement.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

void ButtonElement::update() {
    if (ImGui::Button(getText().c_str())) {
        clickEvent.trigger();
    }
}

const std::string &ButtonElement::getText() const {
    return _text;
}

void ButtonElement::setText(std::string text) {
    _text = std::move(text);
}

ButtonElement::ButtonElement(Core::Application *application, std::string text) : Element{application},
                                                                                 _text{std::move(text)} {

}

} // Elements
