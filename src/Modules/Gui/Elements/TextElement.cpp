//
// Created by packa on 13/10/2024.
//

#include <imgui.h>
#include "TextElement.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

void TextElement::update() {
    if (_isWrapped)
    {
        ImGui::TextWrapped("%s", _text.c_str());
    }
    else
    {
        ImGui::Text("%s", _text.c_str());
    }

    Element::update();
}

const std::string &TextElement::getText() const {
    return _text;
}

void TextElement::setText(std::string text) {
    _text = std::move(text);
}

TextElement::TextElement(Core::Application *application, std::string text) : Element(application), _text(std::move(text)) {

}

bool TextElement::isWrapped() const {
    return _isWrapped;
}

void TextElement::setWrapped(bool wrapped) {
    _isWrapped = wrapped;
}

} // Elements
