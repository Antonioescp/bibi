//
// Created by packa on 13/10/2024.
//

#include <imgui.h>
#include "TextElement.hpp"

namespace Bibi::Module::Gui::
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

TextElement::TextElement(GLFWwindow *window, std::string text) : Element(window), _text(std::move(text)) {

}

} // Elements
