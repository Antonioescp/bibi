//
// Created by packa on 11/10/2024.
//

#include "Element.hpp"

namespace Bibi::Modules::Gui {
    using Base = Core::Lifecycle::DeferredCollection<IElement, IElement>;

    Element::Element(Core::Application *application) : _application{application} {}

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
        for (auto &element: _items) {
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

    void Element::handlePendingItemsOperations() {
        for (auto& item : _itemsToAdd) {
            item->setParent(this);
        }

        for (auto& item : _itemsToRemove) {
            item->setParent(nullptr);
        }

        DeferredCollection::handlePendingItemsOperations();
    }
} // Gui