//
// Created by packa on 9/10/2024.
//

#include "ImGuiModule.hpp"

#include <memory>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Core/UI/BibiMainMenuElement.hpp"
#include "Core/UI/BibiAboutWindowElement.hpp"
#include "Core/UI/ObjectListWindow.hpp"
#include "Core/UI/ElementTag.hpp"
#include "Core/UI/InspectorWindow.hpp"
#include "Core/UI/InfoWindow.hpp"
#include "Core/UI/FileExplorerElement.h"

using namespace Bibi::Modules::Logging;

namespace Bibi::Modules::Gui {
    const std::string ImGuiModule::name = "imgui";

    void ImGuiModule::setUp() {
        initializeImGui();
        registerElements();
        _elements.setUp();
    }

    void ImGuiModule::update() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        _elements.update();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiModule::tearDown() {
        _logger->info("Tearing down imgui");

        _elements.tearDown();

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        _logger->info("imgui teardown complete");
    }

    void ImGuiModule::initializeImGui() {
        _logger = Logger::get(ImGuiModule::name);
        _logger->info("Setting up imgui");

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(_application->getMainWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 150");

        _logger->info("imgui setup complete");
    }

    void ImGuiModule::registerElements() {
        using namespace Bibi::Core::UI;
        auto mainMenuBar = std::make_unique<BibiMainMenuElement>(_application);
        _elements.add(std::move(mainMenuBar));

        auto aboutWindow{ std::make_unique<BibiAboutWindowElement>(_application) };
        _elements.add(std::move(aboutWindow));

        auto subjectListWindow{ std::make_unique<ObjectListWindow>(_application) };
        subjectListWindow->setTag(ElementTag::WindowObjectList);
        _elements.add(std::move(subjectListWindow));

        auto inspectorWindow{ std::make_unique<InspectorWindow>(_application) };
        inspectorWindow->setTag(ElementTag::WindowInspector);
        _elements.add(std::move(inspectorWindow));

        auto infoWindow{ std::make_unique<InfoWindow>(_application) };
        _elements.add(std::move(infoWindow));

        auto fileExplorer { std::make_unique<FileExplorerElement>("data")};
        _elements.add(std::move(fileExplorer));
    }
} // Modules
