//
// Created by packa on 12/10/2024.
//

#ifndef BIBI_WINDOWELEMENT_HPP
#define BIBI_WINDOWELEMENT_HPP

#include <string>
#include "Module/Gui/Element.hpp"

namespace Bibi::Module::Gui::
inline Elements {

class WindowElement : public Element {
public:
    using Element::Element;
    WindowElement(GLFWwindow* window, std::string title);
    void render() override;

    [[nodiscard]] std::string getTitle() const;
    void setTitle(std::string title);

    [[nodiscard]] bool isOpen() const;
    void open();
    void close();

private:
    bool _isOpen{ false };
    std::string _title{};
};

} // Elements

#endif //BIBI_WINDOWELEMENT_HPP
