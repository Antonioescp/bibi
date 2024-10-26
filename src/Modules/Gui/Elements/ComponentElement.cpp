//
// Created by packa on 25/10/2024.
//

#include "ComponentElement.hpp"
#include "TextElement.hpp"
#include "LabelElement.hpp"


namespace Bibi::Modules::Gui::
inline Elements {

ComponentElement::ComponentElement(Core::Component &component) : _component{component} {
}

void ComponentElement::setUp() {
    // Estableciendo un título para el componente, solamente para que el usuario sepa que componente está viendo
    auto componentTitleText{std::make_unique<LabelElement>("Componente:", _component.getName())};
    _elements.add(std::move(componentTitleText));

    // Serializando el componente a un elemento
    auto element { _component.serializeToElement() };
    if (!element) {
        auto &object{_component.getObject()};
        _logger->warn(
                "El componente {} del objeto {} retorno un valor nulo para su elemento, pista: no deberia!, probablemente falte implementar el método serializeToElement() en el componente.",
                _component.getName(), object.getTag());
        return;
    }

    _elements.add(std::move(element));
}

const char *ComponentElement::getLoggerName() {
    return "imgui";
}

} // Elements
