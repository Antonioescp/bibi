//
// Created by packa on 21/10/2024.
//

#ifndef BIBI_INFOWINDOW_HPP
#define BIBI_INFOWINDOW_HPP

#include "Modules/Gui/Element.hpp"

namespace Bibi::Core::UI {

    class InfoWindow : public Modules::Gui::Element {
    public:
        using Element::Element;
        void setUp() override;
        void update() override;

        void open();
        void close();

    protected:
        bool _isOpen{ false };
    };

} // UI
// Core
// Bibi

#endif //BIBI_INFOWINDOW_HPP
