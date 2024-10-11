//
// Created by packa on 10/10/2024.
//

#include <imgui.h>

#include "SomeWindow.hpp"

namespace Bibi::Module::Gui::
inline Elements {

void SomeWindow::render() {
    if (_isOpen) {
        ImGui::Begin("Some Window", &_isOpen);
        ImGui::End();
    }
}

void SomeWindow::setUp() {

}

bool SomeWindow::isOpen() const {
    return _isOpen;
}

void SomeWindow::open() {
    _isOpen = true;
}

void SomeWindow::close() {
    _isOpen = false;
}

void SomeWindow::toggle() {
    _isOpen = !_isOpen;
}

} // Elements