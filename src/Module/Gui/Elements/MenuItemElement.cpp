//
// Created by packa on 11/10/2024.
//

#include <imgui.h>
#include "MenuItemElement.hpp"

namespace Bibi::Module::Gui::
inline Elements {

MenuItemElement::MenuItemElement(GLFWwindow *window, std::string _optionName) : Element(window),
                                                                                _optionName(std::move(_optionName)) {}

void MenuItemElement::render() {
    if (ImGui::MenuItem(_optionName.c_str())) {
        _clickEvent.trigger();
    }
}

void MenuItemElement::setOptionName(std::string optionName) {
    _optionName = std::move(optionName);
}

std::string MenuItemElement::getOptionName() {
    return _optionName;
}

Core::Events::Event<> &MenuItemElement::onClick() {
    return _clickEvent;
}


} // Elements
