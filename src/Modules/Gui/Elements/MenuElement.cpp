//
// Created by packa on 11/10/2024.
//

#include <imgui.h>
#include "MenuElement.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

void MenuElement::update() {
    if (ImGui::BeginMenu(_title.c_str())) {
        Element::update();
        ImGui::EndMenu();
    }
}

MenuElement::MenuElement(Core::Application *application, std::string _title) : Element(application), _title(std::move(_title)) {}

} // Elements
