//
// Created by packa on 21/10/2024.
//

#ifndef BIBI_LIFECYCLE_HPP
#define BIBI_LIFECYCLE_HPP

#include <concepts>
namespace Bibi::Core::Concepts {

    /**
     * Revisa si el tipo T cumple con los requisitos para ser considerado como implementador de ILifecycleAware.
     * Se utiliza para diferenciar las interfaces hijas de las clases hijas.
     * @tparam T El tipo a comprobar.
     * @note Es necesario para saber si una clase es concreta o abstracta con respecto a ILifecycleAware.
     */
    template <typename T>
    concept IsLifecycle = requires(T a) {
        { a.setUp() } -> std::same_as<void>;
        { a.run() } -> std::same_as<void>;
        { a.tearDown() } -> std::same_as<void>;
    };

} // Concepts

#endif //BIBI_LIFECYCLE_HPP
