//
// Created by packa on 25/10/2024.
//

#include <imgui.h>
#include "LabelElement.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

LabelElement::LabelElement(std::string label, std::string text) : _label{std::move(label)}, _text{std::move(text)} {
}

void LabelElement::update() {
    ImGui::Text("%s", _label.c_str());
    ImGui::SameLine();
    ImGui::Text("%s", _text.c_str());
}

const std::string &LabelElement::getLabel() const {
    return _label;
}

void LabelElement::setLabel(std::string label) {
    _label = std::move(label);
}

const std::string &LabelElement::getText() const {
    return _text;
}

void LabelElement::setText(std::string text) {
    _text = std::move(text);
}

} // Elements
