//
// Created by packa on 11/10/2024.
//

#include "Element.hpp"

namespace Bibi::Modules::Gui {
    Element::Element(Core::Application *application) : _application{application} {}

    void Element::update() {
        for (auto &element: _childrenElements) {
            element->update();
        }

        this->handlePendingElements();
    }

    void Element::setUp() {
        this->handlePendingElements();
    }

    void Element::tearDown() {
        for (auto &element: _childrenElements) {
            element->tearDown();
        }
    }

    void Element::addElement(std::unique_ptr<IElement> element) {
        element->setParent(this);
        _elementsToAdd.push_back(std::move(element));
    }

    void Element::removeElements(std::string tag) {
        for (auto &element: _childrenElements) {
            if (element->getTag() == tag) {
                _elementsToRemove.push_back(element.get());
            }
        }
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

    Core::Application *Element::getApplication() {
        return _application;
    }

    void Element::setApplication(Core::Application *application) {
        _application = application;
    }

    IElement *Element::getChildByTag(std::string_view tag) {
        for (auto &element: _childrenElements) {
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

    void Element::removeElement(IElement *element) {
        _elementsToRemove.push_back(element);
    }

    void Element::handlePendingElements() {
        // Removes the elements pending to remove
        for (auto &element: _elementsToRemove | std::views::reverse) {
            element->tearDown();
        }

        auto remover = std::remove_if(_childrenElements.begin(), _childrenElements.end(), [this](auto &child) {
            return std::find(_elementsToRemove.begin(), _elementsToRemove.end(), child.get()) != _elementsToRemove.end();
        });

        _childrenElements.erase(remover, _childrenElements.end());
        _elementsToRemove.clear();

        // Adds the elements pending to add
        for (auto &element: _elementsToAdd) {
            element->setUp();
            _childrenElements.push_back(std::move(element));
        }

        _elementsToAdd.clear();
    }
} // Gui