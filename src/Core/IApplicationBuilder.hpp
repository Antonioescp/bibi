//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_IAPPLICATIONBUILDER_HPP
#define BIBI_IAPPLICATIONBUILDER_HPP

#include <string>

#include "Application.hpp"
#include "Modules/IModule.hpp"

namespace Bibi::Core {

    /**
     * Interfaz necesaria para construir una aplicación.
     */
    class IApplicationBuilder {
    public:

        /**
         * Establece las dimensiones de la ventana principal de la aplicación.
         * @param width Anchura de la ventana.
         * @param height Altura de la ventana.
         * @return El builder de la aplicación.
         */
        virtual IApplicationBuilder& setDimensions(int width, int height) = 0;

        /**
         * Establece el título de la ventana principal de la aplicación.
         * @param title Titulo de la ventana.
         * @return El builder de la aplicación.
         */
        virtual IApplicationBuilder& setTitle(std::string title) = 0;

        /**
         * Añade un módulo a la aplicación.
         * @param module El módulo a añadir.
         * @return El builder de la aplicación.
         */
        virtual IApplicationBuilder& addModule(std::unique_ptr<Modules::IModule> module) = 0;

        /**
         * Construye la aplicación realizando todas las configuraciones necesarias.
         * @return La aplicación construida.
         */
        virtual Application build() = 0;
    };

} // Application

#endif //BIBI_IAPPLICATIONBUILDER_HPP
