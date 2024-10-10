//
// Created by packa on 9/10/2024.
//

#include <imgui.h>
#include <GLFW/glfw3.h>

#include "MenuBarElement.hpp"

namespace Bibi::Module::Gui {
    void MenuBarElement::render(GLFWwindow* window) {
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Exit")) {
                    glfwSetWindowShouldClose(window, GLFW_TRUE);
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
    }
} // Gui