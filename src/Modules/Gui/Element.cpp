//
// Created by packa on 11/10/2024.
//

#include "Element.hpp"

namespace Bibi::Modules::Gui {
    Element::Element(Core::Application *application) : _application{application} {}

    void Element::render() {
        for (auto &element : _childrenElements) {
            element->render();
        }
    }

    void Element::setUp() {
        for (auto &element : _childrenElements) {
            element->setUp();
        }
    }

    void Element::tearDown() {
        for (auto &element : _childrenElements) {
            element->tearDown();
        }
    }

    void Element::addElement(std::unique_ptr<IElement> element) {
        element->setParent(this);
        _childrenElements.push_back(std::move(element));
    }

    void Element::removeElement(std::string tag) {
        auto remover = std::remove_if(_childrenElements.begin(), _childrenElements.end(), [&tag](auto &element){
            auto isTag = element->getTag() == tag;
            if (isTag) {
                element->setParent(nullptr);
            }
            return isTag;
        });
        _childrenElements.erase(remover, _childrenElements.end());
    }

    void Element::clearElements() {
        _childrenElements.clear();
    }

    std::vector<std::unique_ptr<IElement>> &Element::getElements() {
        return _childrenElements;
    }

    void Element::setTag(std::string tag) {
        _tag = tag;
    }

    std::string Element::getTag() {
        return _tag;
    }

    void Element::setParent(IElement *parent) {
        _parent = parent;
    }

    IElement *Element::getParent() {
        return _parent;
    }

    Core::Application * Element::getApplication() {
        return _application;
    }

    void Element::setApplication(Core::Application *application) {
        _application = application;
    }

    IElement *Element::getChildByTag(std::string_view tag) {
        for (auto &element : _childrenElements) {
            if (element->getTag() == tag) {
                return element.get();
            }

            auto child = element->getChildByTag(tag);
            if (child) {
                return child;
            }
        }

        return {};
    }
} // Gui