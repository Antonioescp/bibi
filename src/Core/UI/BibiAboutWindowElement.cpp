//
// Created by packa on 13/10/2024.
//

#include "BibiAboutWindowElement.hpp"
#include "Core/UI/ElementTag.hpp"
#include "Module/Gui/ImGuiModule.hpp"
#include "Module/Gui/Elements/WindowElement.hpp"
#include "Module/Gui/Elements/MenuItemElement.hpp"
#include "Module/Gui/Elements/TextElement.hpp"

namespace Bibi::Core::UI {

    void BibiAboutWindowElement::setUp() {
        using namespace Bibi::Module::Gui;

        auto window{ std::make_unique<WindowElement>(_window) };
        window->setTitle("About");

        auto aboutMenuOption{ ImGuiModule::getElementByTag<MenuItemElement>(ElementTag::MainMenuHelpAbout)  };
        aboutMenuOption->onClick().subscribe([self = window.get()]() {
            self->open();
        });

        auto aboutText{
            "Bibi Engine es un motor de física interactivo realizado con propositos didacticos,\n"
            "con el objetivo de enseñar los conceptos básicos de la física de una manera interactiva\n\n"
            "Desarrollado por:\n"
            "  - Juan A. Pérez.\n"
            "  - Harold J. Moreno.\n"
        };

        auto text{ std::make_unique<TextElement>(_window, aboutText) };
        window->addElement(std::move(text));
        this->addElement(std::move(window));
        Element::setUp();
    }
} // UI
