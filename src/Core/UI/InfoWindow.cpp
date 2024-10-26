//
// Created by packa on 21/10/2024.
//

#include <imgui.h>
#include "InfoWindow.hpp"

#include "Modules/Gui/ImGuiModule.hpp"
#include "Modules/Gui/Elements/MenuItemElement.hpp"
#include "Core/UI/ElementTag.hpp"

namespace Bibi::Core::UI {
    void InfoWindow::setUp() {
        using namespace Modules::Gui;

        auto ui{ _application->getModule<ImGuiModule>() };
        auto debugOption{ ui->getElementByTag<MenuItemElement>(ElementTag::MainMenuWindowsDebug) };
        debugOption->onClick().subscribe([this] {
            open();
        });
    }

    void InfoWindow::update() {
        if (_isOpen) {
            ImGui::ShowMetricsWindow(&_isOpen);
        }
    }

    void InfoWindow::open() {
        _isOpen = true;
    }

    void InfoWindow::close() {
        _isOpen = false;
    }
} // UI
// Core
// Bibi