//
// Created by packa on 21/10/2024.
//

#ifndef BIBI_ELEMENTCOLLECTION_HPP
#define BIBI_ELEMENTCOLLECTION_HPP

#include "Element.hpp"
#include "IElement.hpp"
#include "Core/Lifecycle/DeferredCollection.hpp"

namespace Bibi::Modules::Gui:: inline Elements {
    class ElementCollection : public Core::Lifecycle::DeferredCollection<Element, IElement> {
    public:
        using Core::Lifecycle::DeferredCollection<Element, IElement>::DeferredCollection;
    };
}

#endif //BIBI_ELEMENTCOLLECTION_HPP
