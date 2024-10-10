//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_MENUBARELEMENT_HPP
#define BIBI_MENUBARELEMENT_HPP

#include "Module/Gui/IElement.hpp"

namespace Bibi::Module::Gui {

    class MenuBarElement : public IElement {
    public:
        void render(GLFWwindow* window) override;
    };

} // Gui

#endif //BIBI_MENUBARELEMENT_HPP
