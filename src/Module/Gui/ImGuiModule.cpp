//
// Created by packa on 9/10/2024.
//

#include "ImGuiModule.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "IElement.hpp"
#include "Module/Gui/Elements/MenuBarElement.hpp"
#include "Module/Gui/Elements/SomeWindow.hpp"
#include "Core/Events/Function.hpp"

using namespace Bibi::Module::Logging;

namespace Bibi::Module::Gui {
    const std::string ImGuiModule::name = "imgui";

    void ImGuiModule::setUp(GLFWwindow* window) {
        initializeImGui(window);
        registerElements(window);

        for (auto& element : _elements) {
            element->setUp();
        }
    }

    void ImGuiModule::run(GLFWwindow *window) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        for (auto& element : _elements) {
            element->render();
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiModule::tearDown(GLFWwindow* window) {
        _logger->info("Tearing down imgui");
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        _logger->info("imgui teardown complete");
    }

    void ImGuiModule::addElement(std::unique_ptr<IElement> element) {
        _elements.push_back(std::move(element));
    }

    void ImGuiModule::initializeImGui(GLFWwindow *window) {
        _logger = Logger::get(ImGuiModule::name);
        _logger->info("Setting up imgui");

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 150");

        _logger->info("imgui setup complete");
    }

    void ImGuiModule::registerElements(GLFWwindow *window) {
        auto someWindow = std::make_unique<SomeWindow>(window);
        auto menuBar = std::make_unique<MenuBarElement>(window);

        using namespace Core::Events;
        menuBar->getToggleWindowEvent().subscribe([target = someWindow.get()]{
            target->toggle();
        });

        this->addElement(std::move(someWindow));
        this->addElement(std::move(menuBar));
    }
} // Module
