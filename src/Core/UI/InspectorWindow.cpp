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
#include "Modules/Logging/Logger.hpp"

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
        objectListWindow->objectSelectedEvent.subscribe([](const Core::Object& object) {
            auto logger{ Logger::get("core") };
            logger->info("Object selected: {}", object.getTag());
        });

        // Adding the window
        this->addElement(std::move(window));
        Element::setUp();
    }
} // UI
