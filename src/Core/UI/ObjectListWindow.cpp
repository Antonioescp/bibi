//
// Created by packa on 17/10/2024.
//

#include <memory>

#include "ObjectListWindow.hpp"
#include "Modules/Gui/Elements/WindowElement.hpp"
#include "Modules/Gui/ImGuiModule.hpp"
#include "Modules/Gui/Elements/MenuItemElement.hpp"
#include "Modules/Gui/Elements/TreeNodeElement.hpp"
#include "Core/UI/ElementTag.hpp"
#include "Modules/Gui/Elements/MenuElement.hpp"
#include "Modules/Gui/Elements/ButtonElement.hpp"

namespace Bibi::Core::UI {
    ObjectListWindow::ObjectListWindow(Core::Application *application, const std::vector<Core::Object*>& objects) : Element(application) {
        for (auto object : objects) {
            _objects.push_back(object);
        }
    }

    void ObjectListWindow::setUp() {
        using namespace Modules::Gui;

        // Creating the window
        auto window{std::make_unique<WindowElement>(_application, "Object list")};

        // Button to add a new object
        auto addButton = std::make_unique<ButtonElement>(_application, "Add object");
        addButton->clickEvent.subscribe([this, target = window.get()] {
            auto object = std::make_unique<Core::Object>();
            object->setTag(std::format("Object{}", _application->getObjects().size() + 1));
            _application->addObject(std::move(object));

            // Rebuilding the tree
            target->removeElements<TreeNodeElement>();
            this->buildTree(target);
        });

        window->addElement(std::move(addButton));

        // Listening to the click event of the menu item to open the window
        auto ui{_application->getModule<ImGuiModule>()};
        auto showSubjectWindowOption{ui->getElementByTag<MenuItemElement>(ElementTag::MainMenuWindowsSubjectList)};

        showSubjectWindowOption->onClick().subscribe([target = window.get()] {
            target->open();
        });

        // Building object tree
        this->buildTree(window.get());

        addElement(std::move(window));
        Element::setUp();
    }

    std::unique_ptr<Modules::Gui::TreeNodeElement> ObjectListWindow::buildObjectTree(Core::Object *object) {
        auto treeNode{std::make_unique<Modules::Gui::TreeNodeElement>(_application, object->getTag())};

        for (auto child : object->getChildren()) {
            auto childTreeNode{ this->buildObjectTree(child) };

            childTreeNode->clickEvent.subscribe([this, obj = child] (auto& name) {
                objectSelectedEvent.trigger(*obj);
            });

            treeNode->addElement(std::move(childTreeNode));
        }

        return treeNode;
    }

    void ObjectListWindow::buildTree(Modules::Gui::WindowElement* window) {
        for (auto& object : _application->getRootObjects()) {
            auto treeNode{ this->buildObjectTree(object) };

            treeNode->clickEvent.subscribe([this, obj = object] (auto& name) {
                objectSelectedEvent.trigger(*obj);
            });

            window->addElement(std::move(treeNode));
        }
    }
} // UI
