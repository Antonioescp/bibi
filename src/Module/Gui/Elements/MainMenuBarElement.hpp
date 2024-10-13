//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_MAINMENUBARELEMENT_HPP
#define BIBI_MAINMENUBARELEMENT_HPP

#include <functional>
#include <string>
#include <utility>
#include "Module/Gui/Element.hpp"
#include "Core/Events/Event.hpp"

namespace Bibi::Module::Gui:: inline Elements {

    class MainMenuBarElement : public Element {
    public:
        using Element::Element;
        MainMenuBarElement() = default;
        void render() override;
    };

} // Gui

#endif //BIBI_MAINMENUBARELEMENT_HPP
