//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IELEMENT_HPP
#define BIBI_IELEMENT_HPP

namespace Bibi::Module::Gui {

    class IElement {
    public:
        virtual ~IElement() = default;
        virtual void render(GLFWwindow* window) = 0;
    };

} // Module

#endif //BIBI_IELEMENT_HPP
