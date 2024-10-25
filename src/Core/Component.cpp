//
// Created by packa on 20/10/2024.
//

#include "Component.hpp"
#include "Object.hpp"

namespace Bibi::Core {
    Component::Component(Object &object) : _object{object} {

    }

    std::string Component::getTag() const {
        return _tag;
    }

    void Component::setTag(std::string tag) {
        _tag = std::move(tag);
    }
} // Core
