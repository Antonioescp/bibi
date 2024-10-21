//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMGUIMODULE_HPP
#define BIBI_IMGUIMODULE_HPP

#include <string>
#include <span>
#include <spdlog/logger.h>
#include "Modules/Logging/Logger.hpp"
#include "Modules/Gui/IElement.hpp"

namespace Bibi::Modules::Gui {

    /**
     * Modulo que se encarga de la interfaz gráfica de usuario.
     * Realiza la inicialización y limpieza de ImGui y se encarga de la actualización de los elementos de la interfaz.
     */
    class ImGuiModule : public IModule {
    public:
        /**
         * Nombre del módulo.
         * @note Se utiliza para obtener un logger con el nombre del modulo.
         */
        static const std::string name;

        /**
         * Configura ImGui, registra los elementos de UI y llama al método setUp de cada uno de ellos.
         */
        void setUp() override;

        /**
         * Actualiza los elementos de la interfaz gráfica.
         */
        void update() override;

        /**
         * Llama al método tearDown de cada uno de los elementos de la interfaz y limpia ImGui.
         */
        void tearDown() override;

        /**
         * Añade un elemento a la interfaz.
         * @param element
         */
        void addElement(std::unique_ptr<IElement> element);

        /**
         * Devuelve los elementos de la interfaz.
         * @return Todos los elementos de la interfaz.
         */
        auto getElements();

        /**
         * Devuelve un elemento de la interfaz por su tag.
         * @tparam TElement El tipo de elemento que se desea obtener.
         * @param tag El tag del elemento que se desea obtener.
         * @return El elemento con el tag especificado o nullptr si no se encuentra.
         */
        template <typename TElement>
        requires std::derived_from<TElement, IElement>
        TElement* getElementByTag(const std::string& tag) {
            for (auto& element : s_elements) {
                if (auto converted{ dynamic_cast<TElement*>(element.get()) }; element->getTag() == tag && converted != nullptr) {
                    return converted;
                }

                if (auto found{ element->getChildByTag(tag) }; found) {
                    return dynamic_cast<TElement*>(found);
                }
            }

            return {};
        }

    private:
        /**
         * Logger del módulo.
         */
        std::shared_ptr<spdlog::logger> _logger{};

        /**
         * Elementos de la interfaz.
         */
        std::vector<std::unique_ptr<IElement>> s_elements{};

        /**
         * Realiza la inicialización de ImGui.
         */
        void initializeImGui();

        /**
         * Registra los elementos de la interfaz.
         */
        void registerElements();
    };

} // Modules

#endif //BIBI_IMGUIMODULE_HPP
