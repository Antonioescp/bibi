//
// Created by packa on 19/10/2024.
//

#ifndef BIBI_BUTTONELEMENT_HPP
#define BIBI_BUTTONELEMENT_HPP

#include "Core/Events/Event.hpp"
#include "Core/Events/Function.hpp"
#include "Modules/Gui/Element.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

class ButtonElement : public Element {
public:
    using Element::Element;
    ButtonElement(Core::Application *application, std::string text);
    void update() override;

    [[nodiscard]] const std::string& getText() const;
    void setText(std::string text);

    Core::Events::Event<> clickEvent{};

private:
    std::string _text{};
};

} // Elements

#endif //BIBI_BUTTONELEMENT_HPP
