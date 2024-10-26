//
// Created by packa on 26/10/2024.
//

#ifndef BIBI_ENUM_HPP
#define BIBI_ENUM_HPP

#include <string>

namespace Bibi::Core {

    template <typename TUnderlying>
    class Enum {
    public:
        virtual ~Enum() = default;

        bool operator==(const TUnderlying& other) const {
            return this->getValue() == other.getValue()
                && this->getName() == other.getName();
        }

        [[nodiscard]] inline const TUnderlying& getValue() const {
            return _value;
        }

        [[nodiscard]] inline const std::string& getName() const {
            return _name;
        }

    protected:
        Enum(std::string name, const TUnderlying& value) : _name{std::move(name)}, _value{value} {}
        Enum(std::string name, TUnderlying&& value) : _name{std::move(name)}, _value{value} {}

    private:
        TUnderlying _value;
        std::string _name;
    };

} // Core

#endif //BIBI_ENUM_HPP
