//
// Created by packa on 11/10/2024.
//

#ifndef BIBI_MENUITEMELEMENT_HPP
#define BIBI_MENUITEMELEMENT_HPP

#include "Core/Events/Event.hpp"
#include "Module/Gui/Element.hpp"

namespace Bibi::Module::Gui::
inline Elements {

class MenuItemElement : public Element {
public:
    MenuItemElement(GLFWwindow* window, std::string _optionName);
    void render() override;

    void setOptionName(std::string optionName);
    std::string getOptionName();

    Core::Events::Event<>& onClick();
private:
    std::string _optionName;
    Core::Events::Event<> _clickEvent;
};

} // Elements
// Gui
// Module
// Bibi

#endif //BIBI_MENUITEMELEMENT_HPP
