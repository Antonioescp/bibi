//
// Created by packa on 18/10/2024.
//

#include "Application.hpp"
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
        _components.setUp();
    }

    void Object::update() {
        _components.update();
    }

    void Object::tearDown() {
        _components.tearDown();
    }

    Core::Lifecycle::DeferredCollection<Component> &Object::getComponents() {
        return _components;
    }

    Object::Object(Application *application) : _application(application) {

    }

    Application* Object::getApplication() {
        return _application;
    }

    void Object::setApplication(Application *application) {
        _application = application;
    }
} // Core
