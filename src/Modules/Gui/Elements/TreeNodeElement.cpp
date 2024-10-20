//
// Created by packa on 19/10/2024.
//

#include <imgui.h>
#include "TreeNodeElement.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

const std::string &TreeNodeElement::getName() const {
    return _name;
}

void TreeNodeElement::setName(std::string name) {
    _name = std::move(name);
}

void TreeNodeElement::update() {
    auto shouldRender{ ImGui::TreeNode(_name.c_str()) };

    if (ImGui::IsItemClicked()) {
        clickEvent.trigger(_name);
    }

    if (shouldRender) {
        Element::update();
        ImGui::TreePop();
    }
}

TreeNodeElement::TreeNodeElement(Core::Application *application, std::string name) : Element(application),
                                                                                     _name(std::move(name)) {

}

} // Elements
