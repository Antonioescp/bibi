//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULE_HPP
#define BIBI_IMODULE_HPP

#include "Core/Lifecycle/ILifecycleAware.hpp"

namespace Bibi::Core {
    class Application;
}

namespace Bibi::Modules {

    /**
     * Interfaz para los módulos de la aplicación.
     */
    class IModule : public Core::Lifecycle::ILifecycleAware {
    public:
        ~IModule() override = default;

        /**
         * Inicializa el módulo.
         * @note Este método se llama una sola vez antes del primer frame de la aplicación.
         */
        void setUp() override {
            // Do nothing by default
        }

        /**
         * Actualiza el módulo.
         * @note Este método se llama por cada frame de la aplicación.
         */
        void update() override {
            // Do nothing by default
        }

        /**
         * Limpia el módulo.
         * @note Este método se llama una sola vez al cerrar la aplicación.
         */
        void tearDown() override {
            // Do nothing by default
        }

        /**
         * Establece la aplicación a la que pertenece el módulo.
         * @param application La aplicación a la que pertenece el módulo.
         */
        void setApplication(Core::Application *application) { _application = application; }

        /**
         * Obtiene la aplicación a la que pertenece el módulo.
         * @return La aplicación a la que pertenece el módulo.
         */
        [[nodiscard]] Core::Application *getApplication() const { return _application; }

    protected:
        /**
         * La aplicación a la que pertenece el módulo.
         */
        Core::Application *_application{nullptr};
    };
} // Modules

#endif //BIBI_IMODULE_HPP
