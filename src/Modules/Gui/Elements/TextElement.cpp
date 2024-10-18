//
// Created by packa on 13/10/2024.
//

#include <imgui.h>
#include "TextElement.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

void TextElement::render() {
    ImGui::Text("%s", _text.c_str());

    Element::render();
}

const std::string &TextElement::getText() const {
    return _text;
}

void TextElement::setText(std::string text) {
    _text = std::move(text);
}

TextElement::TextElement(Core::Application *application, std::string text) : Element(application), _text(std::move(text)) {

}

} // Elements
