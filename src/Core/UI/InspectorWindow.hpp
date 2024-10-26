//
// Created by packa on 20/10/2024.
//

#ifndef BIBI_INSPECTORWINDOW_HPP
#define BIBI_INSPECTORWINDOW_HPP

#include "Modules/Gui/Element.hpp"

namespace Bibi::Core::UI {

    class InspectorWindow : public Modules::Gui::Element {
    public:
        using Element::Element;
        void setUp() override;
    };

} // UI

#endif //BIBI_INSPECTORWINDOW_HPP
