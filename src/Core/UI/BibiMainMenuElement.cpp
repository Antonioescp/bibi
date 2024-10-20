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

        auto helpMenu{ std::make_unique<MenuElement>(_application, "Help") };
        auto aboutOption{ std::make_unique<MenuItemElement>(_application, "About") };
        aboutOption->setTag(ElementTag::MainMenuHelpAbout);

        fileMenu->addElement(std::move(exitOption));
        menuBar->addElement(std::move(fileMenu));

        windowsOption->addElement(std::move(subjectListOption));
        menuBar->addElement(std::move(windowsOption));

        helpMenu->addElement(std::move(aboutOption));
        menuBar->addElement(std::move(helpMenu));
        this->addElement(std::move(menuBar));

        Element::setUp();
    }
} // UI