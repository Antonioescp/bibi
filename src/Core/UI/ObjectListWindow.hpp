//
// Created by packa on 17/10/2024.
//

#ifndef BIBI_OBJECTLISTWINDOW_HPP
#define BIBI_OBJECTLISTWINDOW_HPP

#include <ranges>
#include "Core/Application.hpp"
#include "Core/Object.hpp"
#include "Modules/Gui/Element.hpp"
#include "Modules/Gui/Elements/TreeNodeElement.hpp"
#include "Modules/Gui/Elements/WindowElement.hpp"

namespace Bibi::Core::UI {

    class ObjectListWindow : public virtual Modules::Gui::Element {
    public:
        Events::Event<Core::Object&> objectSelectedEvent{};

        using Modules::Gui::Element::Element;
        ObjectListWindow(Core::Application* application, const std::vector<Core::Object*>& objects);
        void setUp() override;

    protected:
        std::vector<Core::Object*> _objects;

    private:
        void buildTree(Modules::Gui::WindowElement* window);
        std::unique_ptr<Modules::Gui::TreeNodeElement> buildObjectTree(Core::Object* object);
    };

} // UI

#endif //BIBI_OBJECTLISTWINDOW_HPP
