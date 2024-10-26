//
// Created by packa on 25/10/2024.
//

#ifndef BIBI_LABELELEMENT_HPP
#define BIBI_LABELELEMENT_HPP

#include "Modules/Gui/Element.hpp"

namespace Bibi::Modules::Gui::
inline Elements {

class LabelElement : public Element {
public:
    explicit LabelElement(std::string label, std::string text);
    void update() override;

    [[nodiscard]] const std::string& getLabel() const;
    void setLabel(std::string label);

    [[nodiscard]] const std::string& getText() const;
    void setText(std::string text);

private:
    std::string _label{};
    std::string _text{};
};

} // Elements
// Gui
// Modules
// Bibi

#endif //BIBI_LABELELEMENT_HPP
