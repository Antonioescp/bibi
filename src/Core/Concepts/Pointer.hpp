//
// Created by packa on 21/10/2024.
//

#ifndef BIBI_POINTER_HPP
#define BIBI_POINTER_HPP

#include <memory>
#include <concepts>

namespace Bibi::Core::Concepts {
    template <typename, typename = void>
    struct has_element_type : std::false_type {};

    template <typename T>
    struct has_element_type<T, std::void_t<typename std::pointer_traits<T>::element_type>> : std::true_type {};

    template <typename T>
    struct underlying_pointer_type_or_type {
        using type = std::conditional_t<
                std::is_pointer_v<T>,
                std::remove_pointer_t<T>,
                std::conditional_t<
                    has_element_type<T>::value,
                    typename std::pointer_traits<T>::element_type,
                    T
                >
        >;
    };

    template <typename T>
    using underlying_pointer_type_or_type_t = typename underlying_pointer_type_or_type<T>::type;
}

#endif //BIBI_POINTER_HPP
