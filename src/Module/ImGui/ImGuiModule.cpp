//
// Created by packa on 9/10/2024.
//

#include "ImGuiModule.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

using namespace Bibi::Module::Logging;

namespace Bibi::Module::Gui {
    void ImGuiModule::setUp(GLFWwindow* window) {
        _logger = Logger::get("imgui");
        _logger->info("Setting up imgui");

        _logger->info("Checking imgui version");
        IMGUI_CHECKVERSION();

        _logger->info("Creating context");
        ImGui::CreateContext();

        _logger->info("Setting up style");
        ImGui::StyleColorsDark();

        _logger->info("Setting up platform and renderer bindings");
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 150");

        _logger->info("imgui setup complete");
    }

    void ImGuiModule::run(GLFWwindow *window) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Hello, world!");
        ImGui::Text("Let's go!");
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiModule::tearDown(GLFWwindow* window) {
        _logger->info("Tearing down imgui");
        _logger->info("Shutting down platform and renderer bindings");

        _logger->info("Shutting down opengl3 implementation");
        ImGui_ImplOpenGL3_Shutdown();

        _logger->info("Shutting down glfw implementation");
        ImGui_ImplGlfw_Shutdown();

        _logger->info("Destroying context");
        ImGui::DestroyContext();

        _logger->info("imgui teardown complete");
    }
} // Module
