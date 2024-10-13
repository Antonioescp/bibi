//
// Created by packa on 11/10/2024.
//

#include <imgui.h>
#include "MenuElement.hpp"

namespace Bibi::Module::Gui::
inline Elements {

void MenuElement::render() {
    if (ImGui::BeginMenu(_title.c_str())) {
        Element::render();
        ImGui::EndMenu();
    }
}

MenuElement::MenuElement(GLFWwindow *window, std::string _title) : Element(window), _title(std::move(_title)) {}

} // Elements
