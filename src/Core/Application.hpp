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

namespace Bibi::Core {

    /**
     * @brief La clase de la aplicación a ejecutar.
     */
    class Application : public Lifecycle::ILifecycleAware {
    public:
        explicit Application(GLFWwindow* window);
        void addModule(std::unique_ptr<Modules::IModule> module);
        void run();

        GLFWwindow* getMainWindow() { return _mainWindow; }

        [[nodiscard]] const std::vector<std::unique_ptr<Core::Object>>& getObjects() const;
        [[nodiscard]] std::vector<Core::Object*> getRootObjects() const;
        void clearObjects();
        void addObject(std::unique_ptr<Core::Object> object);
        void removeObject(const Core::Object* object);

        template <typename TModule>
        requires std::derived_from<TModule, Modules::IModule>
        TModule* getModule() {
            for (auto& module : _modules) {
                if (auto value{ dynamic_cast<TModule*>(module.get()) }; value != nullptr) {
                    return value;
                }
            }
            return nullptr;
        }

    private:
        GLFWwindow* _mainWindow;
        std::vector<std::unique_ptr<Core::Object>> _objects;
        std::vector<std::unique_ptr<Modules::IModule>> _modules;
        std::vector<Modules::IModuleConfigurable*> _configurableModules;
        std::vector<Modules::IModuleDeconstructable*> _deconstructableModules;
        std::vector<Modules::IModuleRunnable*> _runnableModules;

        void setUp();
    };

} // Application

#endif //BIBI_APPLICATION_HPP
