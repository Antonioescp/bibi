//
// Created by packa on 13/10/2024.
//

#ifndef BIBI_BIBIMAINMENUELEMENT_HPP
#define BIBI_BIBIMAINMENUELEMENT_HPP

#include "Module/Gui/Element.hpp"

namespace Bibi::Core::UI {

    class BibiMainMenuElement : public Module::Gui::Element {
    public:
        using Module::Gui::Element::Element;
        ~BibiMainMenuElement() override = default;
        void setUp() override;
    };

} // UI

#endif //BIBI_BIBIMAINMENUELEMENT_HPP
