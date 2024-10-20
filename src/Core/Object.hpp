//
// Created by packa on 18/10/2024.
//

#ifndef BIBI_OBJECT_HPP
#define BIBI_OBJECT_HPP

#include <string>
#include <vector>

namespace Bibi::Core {

    class Object {
    public:
        virtual ~Object() = default;
        [[nodiscard]] const std::string& getTag() const;
        void setTag(std::string tag);

        [[nodiscard]] Object* getParent();
        void setParent(Object* parent);

        void addChild(Object* child);
        void removeChild(Object* child);
        void clearChildren();
        [[nodiscard]] std::vector<Object*>& getChildren();

    protected:
        std::string _tag{};
        Object* _parent{ nullptr };
        std::vector<Object*> _children;
    };

} // Core

#endif //BIBI_OBJECT_HPP
