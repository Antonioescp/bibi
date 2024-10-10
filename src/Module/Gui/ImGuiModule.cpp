//
// Created by packa on 9/10/2024.
//

#include "ImGuiModule.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "IElement.hpp"
#include "Module/Gui/Elements/MenuBarElement.hpp"

using namespace Bibi::Module::Logging;

namespace Bibi::Module::Gui {
    const std::string ImGuiModule::name = "imgui";

    void ImGuiModule::setUp(GLFWwindow* window) {
        initializeImGui(window);
        registerElements(window);
    }

    void ImGuiModule::run(GLFWwindow *window) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        for (auto& element : _elements) {
            element->render(window);
        }

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

    void ImGuiModule::addElement(std::unique_ptr<IElement> element) {
        _elements.push_back(std::move(element));
    }

    void ImGuiModule::initializeImGui(GLFWwindow *window) {
        _logger = Logger::get(ImGuiModule::name);
        _logger->info("Setting up imgui");

        _logger->info("Checking imgui version");
        IMGUI_CHECKVERSION();

        _logger->info("Creating context");
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

        _logger->info("Setting up style");
        ImGui::StyleColorsDark();

        _logger->info("Setting up platform and renderer bindings");
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 150");

        _logger->info("imgui setup complete");
    }

    void ImGuiModule::registerElements(GLFWwindow *window) {
        _logger->info("Registering elements");
        _logger->info("Registering menu bar element");
        auto menuBar = std::make_unique<MenuBarElement>();
        this->addElement(std::move(menuBar));
    }
} // Module
