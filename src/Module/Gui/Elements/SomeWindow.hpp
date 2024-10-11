//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_SOMEWINDOW_HPP
#define BIBI_SOMEWINDOW_HPP

#include "Module/Gui/IElement.hpp"

namespace Bibi::Module::Gui::
inline Elements {

class SomeWindow : public IElement {
public:
    using IElement::IElement;
    ~SomeWindow() override = default;

    void render() override;
    void setUp() override;
    [[nodiscard]] bool isOpen() const;
    void open();
    void close();
    void toggle();

private:
    bool _isOpen{};
};

} // Elements

#endif //BIBI_SOMEWINDOW_HPP
