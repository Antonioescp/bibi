//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_OPENGLAPPLICATIONBUILDER_HPP
#define BIBI_OPENGLAPPLICATIONBUILDER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IApplicationBuilder.hpp"

namespace Bibi::Core {

    /**
     * Construye una aplicación OpenGL.
     */
    class OpenGLApplicationBuilder : public IApplicationBuilder {
    public:
        IApplicationBuilder& setDimensions(int width, int height) override;
        IApplicationBuilder& setTitle(std::string title) override;

        /**
         * Añade un módulo a la aplicación.
         * @param module Módulo a añadir.
         * @return Referencia a la instancia de la aplicación.
         * @note La aplicación tomará posesión del módulo.
         */
        IApplicationBuilder& addModule(std::unique_ptr<Modules::IModule> module) override;
        Application build() override;

    private:
        /**
         * Ancho de la ventana.
         */
        int _width{ 640 };

        /**
         * Alto de la ventana.
         */
        int _height{ 480 };

        /**
         * Título de la ventana.
         */
        std::string _title{ "Application" };

        /**
         * Módulos de la aplicación.
         */
        std::vector<std::unique_ptr<Bibi::Modules::IModule>> _modules;
    };

} // Application

#endif //BIBI_OPENGLAPPLICATIONBUILDER_HPP
