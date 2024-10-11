//
// Created by packa on 9/10/2024.
//

#include <imgui.h>
#include <GLFW/glfw3.h>

#include "MenuBarElement.hpp"

namespace Bibi::Module::Gui::
inline Elements {

void MenuBarElement::render() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Toggle Window")) {
                _toggleWindowEvent.trigger();
            }
            if (ImGui::MenuItem("Exit")) {
                glfwSetWindowShouldClose(_window, GLFW_TRUE);
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void MenuBarElement::setUp() {
}

Core::Events::IEventSubscriber<> &MenuBarElement::getToggleWindowEvent() {
    return _toggleWindowEvent;
}

} // Gui