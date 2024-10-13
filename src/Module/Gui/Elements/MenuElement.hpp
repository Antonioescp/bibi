//
// Created by packa on 11/10/2024.
//

#ifndef BIBI_MENUELEMENT_HPP
#define BIBI_MENUELEMENT_HPP

#include "Module/Gui/Element.hpp"


namespace Bibi::Module::Gui::
inline Elements {

class MenuElement : public Element {
public:
    MenuElement(GLFWwindow* window, std::string _title);
    void render() override;
private:
    std::string _title;
};

} // Elements

#endif //BIBI_MENUELEMENT_HPP
