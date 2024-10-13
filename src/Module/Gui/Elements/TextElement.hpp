//
// Created by packa on 13/10/2024.
//

#ifndef BIBI_TEXTELEMENT_HPP
#define BIBI_TEXTELEMENT_HPP

#include "Module/Gui/Element.hpp"

namespace Bibi::Module::Gui::
inline Elements {

class TextElement : public Element {
public:
    using Element::Element;
    TextElement(GLFWwindow* window, std::string text);
    ~TextElement() override = default;
    void render() override;

    [[nodiscard]] const std::string& getText() const;
    void setText(std::string text);

private:
    std::string _text;
};

} // Elements
// Gui

#endif //BIBI_TEXTELEMENT_HPP
