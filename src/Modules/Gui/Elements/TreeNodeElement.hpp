//
// Created by packa on 19/10/2024.
//

#ifndef BIBI_TREENODEELEMENT_HPP
#define BIBI_TREENODEELEMENT_HPP

#include <string>

#include "Core/Events/Event.hpp"
#include "Core/Events/Function.hpp"
#include "Core/Application.hpp"
#include "Modules/Gui/Element.hpp"

namespace Bibi::Modules::Gui::inline Elements {
    class TreeNodeElement : public Element {
    public:
        Core::Events::Event<const std::string&> clickEvent;

        TreeNodeElement(Core::Application* application, std::string name);
        void update() override;

        [[nodiscard]] const std::string& getName() const;
        void setName(std::string name);

    protected:
        std::string _name;
    };
} // Elements

#endif //BIBI_TREENODEELEMENT_HPP
