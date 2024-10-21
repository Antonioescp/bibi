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

#include "Modules/IModule.hpp"
#include "Object.hpp"
#include "Core/Lifecycle/ILifecycleAware.hpp"
#include "Core/Lifecycle/DeferredCollectionMixin.hpp"

namespace Bibi::Core {

    /**
     * @brief La clase de la aplicación a ejecutar.
     */
    class Application
            : public Core::Lifecycle::DeferredCollectionMixin<Core::Lifecycle::ILifecycleAware, Modules::IModule> {
    public:
        /**
         * Crea una instancia de Application.
         * @param window La ventana principal (GLFW).
         */
        explicit Application(GLFWwindow *window);

    public:

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
        [[nodiscard]] const std::vector<std::unique_ptr<Core::Object>> &getObjects() const;

        /**
         * Obtiene los objetos raíz de la aplicación, es decir, los objetos sin padre.
         * @return Los objetos sin padre de la aplicación.
         */
        [[nodiscard]] std::vector<Core::Object *> getRootObjects() const;

        /**
         * Agrega un objeto a la aplicación.
         * @param object El objeto a agregar.
         */
        void addObject(std::unique_ptr<Core::Object> object);

        /**
         * Elimina un objeto de la aplicación.
         * @param object El objeto a eliminar.
         */
        void removeObject(const Core::Object *object);

        /**
         * Obtiene un módulo de la aplicación.
         * @tparam TModule El tipo de módulo a obtener.
         * @return El módulo si existe, de lo contrario, nullptr.
         */
        template<typename TModule>
        requires std::derived_from<TModule, Modules::IModule>
        TModule *getModule() {
            for (auto &module: _items) {
                if (auto value{dynamic_cast<TModule *>(module.get())}; value != nullptr) {
                    return value;
                }
            }
            return {};
        }

    protected:
        /**
         * Primero establece la aplicacion en los modulos y luego se utiliza la implementacion base.
         */
        void handlePendingItemsOperations() override;

    private:

        /**
         * La ventana principal de la aplicación.
         */
        GLFWwindow *_mainWindow;

        /**
         * Los objetos de la aplicación.
         */
        std::vector<std::unique_ptr<Core::Object>> _objects;
    };

} // Application

#endif //BIBI_APPLICATION_HPP
