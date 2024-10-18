//
// Created by packa on 9/10/2024.
//

#include <imgui.h>
#include "MainMenuBarElement.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

void MainMenuBarElement::render() {
    if (ImGui::BeginMainMenuBar()) {
        Element::render();

//        if (ImGui::BeginMenu("File")) {
//            if (ImGui::MenuItem("Toggle Window")) {
//                _toggleWindowEvent.trigger();
//            }
//            if (ImGui::MenuItem("Exit")) {
//                glfwSetWindowShouldClose(_application, GLFW_TRUE);
//            }
//            ImGui::EndMenu();
//        }
        ImGui::EndMainMenuBar();
    }
}

} // Gui