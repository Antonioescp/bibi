//
// Created by packa on 11/10/2024.
//

#ifndef BIBI_MENUELEMENT_HPP
#define BIBI_MENUELEMENT_HPP

#include "Modules/Gui/Element.hpp"


namespace Bibi::Modules::Gui::
inline Elements {

class MenuElement : public Element {
public:
    MenuElement(Core::Application *application, std::string _title);

    void render() override;

private:
    std::string _title;
};

} // Elements

#endif //BIBI_MENUELEMENT_HPP
