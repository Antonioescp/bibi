//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_MENUBARELEMENT_HPP
#define BIBI_MENUBARELEMENT_HPP

#include <functional>
#include <string>
#include "Module/Gui/IElement.hpp"
#include "Core/Events/Event.hpp"

namespace Bibi::Module::Gui:: inline Elements {

    class MenuBarElement : public IElement {
    public:
        using IElement::IElement;
        void render() override;
        void setUp() override;

        Core::Events::IEventSubscriber<>& getToggleWindowEvent();
    private:
        Core::Events::Event<> _toggleWindowEvent;
    };

} // Gui

#endif //BIBI_MENUBARELEMENT_HPP
