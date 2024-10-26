//
// Created by packa on 25/10/2024.
//

#ifndef BIBI_COMPONENTELEMENT_HPP
#define BIBI_COMPONENTELEMENT_HPP

#include "Core/Component.hpp"
#include "Modules/Gui/Element.hpp"
#include "Modules/Logging/LoggerMixin.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

class ComponentElement : public virtual Element, public virtual Logging::LoggerMixin<ComponentElement> {
public:
    static const char* getLoggerName();

    explicit ComponentElement(Core::Component &component);
    void setUp() override;
private:
    Core::Component &_component;
};

} // Elements

#endif //BIBI_COMPONENTELEMENT_HPP
