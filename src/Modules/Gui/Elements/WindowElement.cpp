//
// Created by packa on 12/10/2024.
//

#include <imgui.h>
#include "WindowElement.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

void WindowElement::update() {
    if (_isOpen) {
        if (ImGui::Begin(_title.c_str(), &_isOpen)) {
            Element::update();
        }
        ImGui::End();
    }
}

std::string WindowElement::getTitle() const {
    return _title;
}

void WindowElement::setTitle(std::string title) {
    _title = std::move(title);
}

bool WindowElement::isOpen() const {
    return _isOpen;
}

void WindowElement::open() {
    _isOpen = true;
}

void WindowElement::close() {
    _isOpen = false;
}

WindowElement::WindowElement(Core::Application *application, std::string title) : Element(application), _title(std::move(title)) {

}

} // Elements