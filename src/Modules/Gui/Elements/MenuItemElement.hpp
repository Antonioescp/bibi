//
// Created by packa on 11/10/2024.
//

#ifndef BIBI_MENUITEMELEMENT_HPP
#define BIBI_MENUITEMELEMENT_HPP

#include "Core/Events/Event.hpp"
#include "Modules/Gui/Element.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

class MenuItemElement : public Element {
public:
    MenuItemElement(Core::Application *application, std::string _optionName);
    void update() override;

    void setOptionName(std::string optionName);
    std::string getOptionName();

    Core::Events::Event<>& onClick();
private:
    std::string _optionName;
    Core::Events::Event<> _clickEvent;
};

} // Elements
// Gui
// Modules
// Bibi

#endif //BIBI_MENUITEMELEMENT_HPP
