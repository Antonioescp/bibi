//
// Created by packa on 13/10/2024.
//

#include "BibiMainMenuElement.hpp"
#include "ElementTag.hpp"
#include "Module/Gui/Elements/MenuElement.hpp"
#include "Module/Gui/Elements/MainMenuBarElement.hpp"
#include "Module/Gui/Elements/MenuItemElement.hpp"

namespace Bibi::Core::UI {
    void BibiMainMenuElement::setUp() {
        using namespace Bibi::Module::Gui;

        auto menuBar = std::make_unique<MainMenuBarElement>(_window);
        auto fileMenu = std::make_unique<MenuElement>(_window, "File");

        auto exitOption = std::make_unique<MenuItemElement>(_window, "Exit");
        exitOption->onClick().subscribe([this]() {
            glfwSetWindowShouldClose(_window, GLFW_TRUE);
        });

        auto helpMenu{ std::make_unique<MenuElement>(_window, "Help") };
        auto aboutOption{ std::make_unique<MenuItemElement>(_window, "About") };
        aboutOption->setTag(ElementTag::MainMenuHelpAbout);

        fileMenu->addElement(std::move(exitOption));
        menuBar->addElement(std::move(fileMenu));
        helpMenu->addElement(std::move(aboutOption));
        menuBar->addElement(std::move(helpMenu));
        this->addElement(std::move(menuBar));

        Element::setUp();
    }
} // UI