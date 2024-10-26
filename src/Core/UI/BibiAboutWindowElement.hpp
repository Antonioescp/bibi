//
// Created by packa on 13/10/2024.
//

#ifndef BIBI_BIBIABOUTWINDOWELEMENT_HPP
#define BIBI_BIBIABOUTWINDOWELEMENT_HPP

#include "Modules/Gui/Element.hpp"

namespace Bibi::Core::UI {

    class BibiAboutWindowElement : public Modules::Gui::Element {
    public:
        using Element::Element;
        ~BibiAboutWindowElement() override = default;
        void setUp() override;
    };

} // UI

#endif //BIBI_BIBIABOUTWINDOWELEMENT_HPP
