//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_APPLICATION_HPP
#define BIBI_APPLICATION_HPP

#include <vector>
#include <memory>
#include <concepts>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Object.hpp"
#include "Modules/IModule.hpp"
#include "Core/Lifecycle/ILifecycleAware.hpp"
#include "Core/Lifecycle/DeferredCollection.hpp"

namespace Bibi::Core {

    /**
     * @brief La clase de la aplicación a ejecutar.
     */
    class Application : public virtual Lifecycle::ILifecycleAware {
    public:
        /**
         * Crea una instancia de Application.
         * @param window La ventana principal (GLFW).
         */
        explicit Application(GLFWwindow *window);

    public:

        /**
         * Configura la aplicación y sus módulos.
         */
        void setUp() override;

        /**
         * Actualiza la aplicacion y sus modulos.
         * @note Este metodo se llama cada frame.
         */
        void update() override;

        /**
         * Limpia la aplicación y los módulos.
         * @note Este metodo se llama una sola vez al cerrar la aplicación.
         */
        void tearDown() override;

        /**
         * Ejecuta la aplicación.
         */
        void run();

        /**
         * Obtiene la ventana principal.
         * @return La ventana principal.
         */
        [[nodiscard]] GLFWwindow *getMainWindow() { return _mainWindow; }

        /**
         * Obtiene los objetos de la aplicación.
         * @note Estos objetos son los objetos del inspector.
         * @note Los objetos se actualizan y dibujan en el orden en que se agregaron.
         * @return Los objetos de la aplicación.
         */
        [[nodiscard]] Lifecycle::DeferredCollection<Object> &getObjects();

        /**
         * Obtiene los objetos raíz de la aplicación, es decir, los objetos sin padre.
         * @return Los objetos sin padre de la aplicación.
         */
        [[nodiscard]] std::vector<Object *> getRootObjects();

        /**
         * Obtiene un módulo de la aplicación.
         * @tparam TModule El tipo de módulo a obtener.
         * @return El módulo si existe, de lo contrario, nullptr.
         */
        template<typename TModule>
        requires std::derived_from<TModule, Modules::IModule>
        TModule *getModule() {
            for (auto &module: _modules) {
                if (auto value{dynamic_cast<TModule *>(module.get())}; value != nullptr) {
                    return value;
                }
            }
            return {};
        }

        /**
         * Obtiene la coleccion de modulos de la aplicacion.
         * @return La coleccion de modulos de la aplicacion.
         */
        [[nodiscard]] Lifecycle::DeferredCollection<Modules::IModule> &getModules();

    private:

        /**
         * La ventana principal de la aplicación.
         */
        GLFWwindow *_mainWindow;

        /**
         * Los objetos de la aplicación.
         */
        Lifecycle::DeferredCollection<Core::Object> _objects;
        Lifecycle::DeferredCollection<Modules::IModule> _modules;
    };

} // Application

#endif //BIBI_APPLICATION_HPP
