//
// Created by packa on 20/10/2024.
//

#include "Component.hpp"
#include "Object.hpp"

namespace Bibi::Core {
    Component::Component(Object &object) : _object{object} {

    }

    std::string Component::getName() const {
        return _name;
    }

    void Component::setName(std::string name) {
        _name = std::move(name);
    }

    Object &Component::getObject() const {
        return _object;
    }
} // Core
