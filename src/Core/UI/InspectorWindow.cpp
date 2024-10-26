//
// Created by packa on 20/10/2024.
//

#include "InspectorWindow.hpp"

#include <memory>
#include "Modules/Gui/Elements/WindowElement.hpp"
#include "Modules/Gui/Elements/MenuItemElement.hpp"
#include "Modules/Gui/ImGuiModule.hpp"
#include "ElementTag.hpp"
#include "ObjectListWindow.hpp"
#include "Modules/Gui/Elements/TextElement.hpp"
#include "Modules/Gui/Elements/ComponentElement.hpp"
#include "Modules/Gui/Elements/LabelElement.hpp"
#include "Modules/Gui/Elements/SeparatorElement.hpp"

namespace Bibi::Core::UI {

    void InspectorWindow::setUp() {
        using namespace Modules::Gui;
        using namespace Modules::Logging;

        auto window{std::make_unique<WindowElement>(_application, "Inspector")};

        // listening for the inspector menu item click event in Windows -> Inspector
        auto ui{_application->getModule<ImGuiModule>()};
        auto inspectorMenuItem{ui->getElementByTag<MenuItemElement>(ElementTag::MainMenuWindowsInspector)};

        inspectorMenuItem->onClick().subscribe([target = window.get()] {
            target->open();
        });

        // Listening for object inspection from object list window
        auto objectListWindow{ui->getElementByTag<ObjectListWindow>(ElementTag::WindowObjectList)};
        objectListWindow->getObjectSelectedEvent().subscribe(
                [this, inspectorWindow = window.get()](Core::Object &object) {

                    auto& elements{inspectorWindow->getElements()};
                    elements.clear();

                    auto nameElement{std::make_unique<LabelElement>("Nombre:", object.getTag())};
                    elements.add(std::move(nameElement));
                    auto nameSeparator{std::make_unique<Modules::Gui::SeparatorElement>()};
                    elements.add(std::move(nameSeparator));

                    for (auto &component: object.getComponents()) {
                        auto componentElement{ std::make_unique<Modules::Gui::ComponentElement>(*component) };
                        elements.add(std::move(componentElement));

                        auto separator{std::make_unique<Modules::Gui::SeparatorElement>()};
                        elements.add(std::move(separator));
                    }
                });

        // Adding the window
        this->getElements().add(std::move(window));
        Element::setUp();
    }
} // UI
