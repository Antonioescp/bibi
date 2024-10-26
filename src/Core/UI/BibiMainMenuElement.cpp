//
// Created by packa on 13/10/2024.
//

#include "BibiMainMenuElement.hpp"
#include "ElementTag.hpp"
#include "Modules/Gui/Elements/MenuElement.hpp"
#include "Modules/Gui/Elements/MainMenuBarElement.hpp"
#include "Modules/Gui/Elements/MenuItemElement.hpp"

namespace Bibi::Core::UI {
    void BibiMainMenuElement::setUp() {
        using namespace Bibi::Modules::Gui;

        auto menuBar = std::make_unique<MainMenuBarElement>(_application);
        auto fileMenu = std::make_unique<MenuElement>(_application, "File");

        auto exitOption = std::make_unique<MenuItemElement>(_application, "Exit");
        exitOption->onClick().subscribe([this]() {
            glfwSetWindowShouldClose(_application->getMainWindow(), GLFW_TRUE);
        });

        auto windowsOption{ std::make_unique<MenuElement>(_application, "Windows") };
        auto subjectListOption{ std::make_unique<MenuItemElement>(_application, "Subject List") };
        subjectListOption->setTag(ElementTag::MainMenuWindowsSubjectList);

        auto inspectorOption{ std::make_unique<MenuItemElement>(_application, "Inspector") };
        inspectorOption->setTag(ElementTag::MainMenuWindowsInspector);

        auto debugOption{ std::make_unique<MenuItemElement>(_application, "Debug") };
        debugOption->setTag(ElementTag::MainMenuWindowsDebug);

        auto helpMenu{ std::make_unique<MenuElement>(_application, "Help") };
        auto aboutOption{ std::make_unique<MenuItemElement>(_application, "About") };
        aboutOption->setTag(ElementTag::MainMenuHelpAbout);

        fileMenu->getElements().add(std::move(exitOption));
        menuBar->getElements().add(std::move(fileMenu));

        windowsOption->getElements().add(std::move(subjectListOption));
        windowsOption->getElements().add(std::move(inspectorOption));
        windowsOption->getElements().add(std::move(debugOption));
        menuBar->getElements().add(std::move(windowsOption));

        helpMenu->getElements().add(std::move(aboutOption));
        menuBar->getElements().add(std::move(helpMenu));
        this->getElements().add(std::move(menuBar));

        Element::setUp();
    }
} // UI