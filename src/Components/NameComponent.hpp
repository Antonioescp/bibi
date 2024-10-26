//
// Created by packa on 21/10/2024.
//

#ifndef BIBI_NAMECOMPONENT_HPP
#define BIBI_NAMECOMPONENT_HPP

#include <string>
#include "Core/Component.hpp"

namespace Bibi::Components {

    class NameComponent : public virtual Core::Component {
    public:
        using Component::Component;
        void setUp() override;

        std::unique_ptr<Modules::Gui::IElement> serializeToElement() override;
    };

} // Components
// Bibi

#endif //BIBI_NAMECOMPONENT_HPP
