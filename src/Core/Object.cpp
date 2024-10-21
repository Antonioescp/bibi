//
// Created by packa on 18/10/2024.
//

#include "Object.hpp"

namespace Bibi::Core {

    const std::string &Object::getTag() const {
        return _tag;
    }

    void Object::setTag(std::string tag) {
        _tag = std::move(tag);
    }

    Object *Object::getParent() {
        return _parent;
    }

    void Object::setParent(Object *parent) {
        _parent = parent;
    }

    void Object::addChild(Object *child) {
        child->setParent(this);
        _children.push_back(child);
    }

    void Object::removeChild(Object *child) {
        _children.erase(std::remove(_children.begin(), _children.end(), child), _children.end());
    }

    void Object::clearChildren() {
        _children.clear();
    }

    const std::vector<Object *> &Object::getChildren() {
        return _children;
    }

    void Object::setUp() {

    }

    void Object::update() {

    }

    void Object::tearDown() {

    }
} // Core
