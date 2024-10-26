//
// Created by packa on 25/10/2024.
//

#ifndef BIBI_RENDERCOMPONENT_HPP
#define BIBI_RENDERCOMPONENT_HPP

#include "Core/Component.hpp"
#include "Rendering/Mesh.hpp"

namespace Bibi::Components {

    class RenderComponent : public virtual Core::Component {
    public:
        using Core::Component::Component;

        void setUp() override;
        std::unique_ptr<Modules::Gui::IElement> serializeToElement() override;

    private:
        Rendering::Mesh mesh{};
    };

} // Components

#endif //BIBI_RENDERCOMPONENT_HPP
