//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IELEMENT_HPP
#define BIBI_IELEMENT_HPP

#include <string>
#include <memory>
#include <vector>

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include "Core/Application.hpp"

namespace Bibi::Modules::Gui {

    /**
     * Interfaz para todos los elementos de la interfaz de usuario.
     * @note Existe una implementacion base de esta clase llamada Element, la clase Element
     * debe ser utilizada como base para todos los elementos de la interfaz de usuario.
     */
    class IElement : public Core::Lifecycle::ILifecycleAware {
    public:
        ~IElement() override = default;

        /**
         * Establece la etiqueta de este elemento.
         * @param tag La etiqueta de este elemento.
         */
        virtual void setTag(std::string tag) = 0;

        /**
         * Obtiene la etiqueta de este elemento.
         * @return La etiqueta de este elemento.
         */
        virtual std::string getTag() = 0;

        /**
         * Establece el padre de este elemento.
         * @param parent El padre de este elemento.
         */
        virtual void setParent(IElement *parent) = 0;

        /**
         * Obtiene el padre de este elemento.
         * @return El padre de este elemento.
         */
        virtual IElement *getParent() = 0;

        /**
         * Obtiene la aplicación a la que pertenece este elemento.
         * @return La aplicación a la que pertenece este elemento.
         */
        virtual Core::Application *getApplication() = 0;

        /**
         * Establece la aplicación a la que pertenece este elemento.
         * @param application La aplicación a la que pertenece este elemento.
         */
        virtual void setApplication(Core::Application *application) = 0;

        /**
         * Obtiene un elemento hijo de este elemento por su etiqueta.
         * @param tag La etiqueta del elemento hijo a obtener.
         * @return El elemento hijo con la etiqueta especificada o nullptr si no se encuentra.
         */
        virtual IElement *getChildByTag(std::string_view tag) = 0;
    };
} // Modules

#endif //BIBI_IELEMENT_HPP
