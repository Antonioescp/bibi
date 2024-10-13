//
// Created by packa on 9/10/2024.
//

#include "ImGuiModule.hpp"

#include <memory>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "IElement.hpp"
#include "Module/Gui/Elements/MainMenuBarElement.hpp"
#include "Module/Gui/Elements/MenuElement.hpp"
#include "Module/Gui/Elements/MenuItemElement.hpp"
#include "Module/Gui/Elements/WindowElement.hpp"
#include "Core/UI/BibiMainMenuElement.hpp"
#include "Core/UI/BibiAboutWindowElement.hpp"

using namespace Bibi::Module::Logging;

namespace Bibi::Module::Gui {
    const std::string ImGuiModule::name = "imgui";
    std::vector<std::unique_ptr<IElement>> ImGuiModule::s_elements;

    void ImGuiModule::setUp(GLFWwindow* window) {
        initializeImGui(window);
        registerElements(window);

        for (auto& element : s_elements) {
            element->setUp();
        }
    }

    void ImGuiModule::run(GLFWwindow *window) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        for (auto& element : s_elements) {
            element->render();
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiModule::tearDown(GLFWwindow* window) {
        _logger->info("Tearing down imgui");

        for (auto& element : s_elements | std::views::reverse) {
            element->tearDown();
        }

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        _logger->info("imgui teardown complete");
    }

    void ImGuiModule::addElement(std::unique_ptr<IElement> element) {
        s_elements.push_back(std::move(element));
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
        using namespace Bibi::Core::UI;
        auto mainMenuBar = std::make_unique<BibiMainMenuElement>(window);
        addElement(std::move(mainMenuBar));

        auto aboutWindow{ std::make_unique<BibiAboutWindowElement>(window) };
        addElement(std::move(aboutWindow));
    }

    auto ImGuiModule::getElements() {
        return s_elements | std::views::transform([](const auto& element) {
            return element.get();
        });
    }
} // Module
