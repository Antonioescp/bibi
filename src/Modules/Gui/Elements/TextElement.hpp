//
// Created by packa on 13/10/2024.
//

#ifndef BIBI_TEXTELEMENT_HPP
#define BIBI_TEXTELEMENT_HPP

#include "Modules/Gui/Element.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

class TextElement : public Element {
public:
    using Element::Element;
    TextElement(Core::Application *application, std::string text);
    ~TextElement() override = default;
    void update() override;

    [[nodiscard]] const std::string& getText() const;
    void setText(std::string text);

    [[nodiscard]] bool isWrapped() const;
    void setWrapped(bool wrapped);

private:
    std::string _text;
    bool _isWrapped{true};
};

} // Elements
// Gui

#endif //BIBI_TEXTELEMENT_HPP
