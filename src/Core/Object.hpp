//
// Created by packa on 18/10/2024.
//

#ifndef BIBI_OBJECT_HPP
#define BIBI_OBJECT_HPP

#include <string>
#include <vector>
#include "Core/Lifecycle/ILifecycleAware.hpp"

namespace Bibi::Core {

    /**
     * @brief Clase base para todos los objetos en el motor.
     * @note esta clase debe ser heredada por todas las clases que representen un objeto en el motor.
     */
    class Object : public Core::Lifecycle::ILifecycleAware {
    public:
        ~Object() override = default;

        /**
         * Configura el objeto.
         */
        void setUp() override;

        /**
         * Actualiza el objeto en cada frame.
         */
        void update() override;

        /**
         * Limpia el objeto al terminar la aplicación.
         */
        void tearDown() override;

        /**
         * @brief Obtiene la etiqueta del objeto.
         * @return La etiqueta del objeto.
         */
        [[nodiscard]] const std::string& getTag() const;

        /**
         * @brief Establece la etiqueta del objeto.
         * @param tag La nueva etiqueta del objeto.
         */
        void setTag(std::string tag);

        /**
         * @brief Obtiene el padre del objeto.
         * @return El padre del objeto.
         */
        [[nodiscard]] Object* getParent();

        /**
         * @brief Establece el padre del objeto.
         * @param parent El nuevo padre del objeto.
         */
        void setParent(Object* parent);

        /**
         * @brief Añade un hijo al objeto.
         * @param child
         */
        void addChild(Object* child);

        /**
         * @brief Elimina un hijo del objeto.
         * @param child
         */
        void removeChild(Object* child);

        /**
         * @brief Obtiene los hijos del objeto.
         * @return coleccion de hijos del objeto.
         */
        [[nodiscard]] const std::vector<Object*>& getChildren();

        /**
         * @brief Elimina todos los hijos del objeto.
         */
        void clearChildren();

    protected:
        /**
         * @brief Etiqueta del objeto.
         */
        std::string _tag{};

        /**
         * @brief Padre del objeto.
         */
        Object* _parent{ nullptr };

        /**
         * @brief Colección de hijos del objeto.
         */
        std::vector<Object*> _children;
    };

} // Core

#endif //BIBI_OBJECT_HPP
