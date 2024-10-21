//
// Created by packa on 11/10/2024.
//

#ifndef BIBI_ELEMENT_HPP
#define BIBI_ELEMENT_HPP

#include <vector>
#include <memory>
#include <ranges>

#include "IElement.hpp"
#include "Core/Application.hpp"
#include "Core/Lifecycle/DeferredCollection.hpp"

namespace Bibi::Modules::Gui {

    class Element : public Core::Lifecycle::DeferredCollection<IElement, IElement> {
    public:
        ~Element() override = default;

        /**
         * Crea una instancia de Element.
         * @param application La aplicación a la que pertenece el elemento.
         */
        explicit Element(Core::Application *application);

        /**
         * Crea una instancia de Element.
         */
        Element() = default;

        /**
         * Elimina todos los elementos hijos de este elemento que sean del tipo especificado.
         * @tparam TElement El tipo de elemento a eliminar.
         * @note Los elementos se eliminan de manera diferida, es decir, se eliminan al inicio del siguiente ciclo de actualización.
         */
        template <typename TElement>
        requires std::derived_from<TElement, IElement>
        void removeElements() {
            for (auto &element : _items) {
                if (dynamic_cast<TElement*>(element.get())) {
                    this->remove(element.get());
                }
            }
        }

        void setTag(std::string tag) override;

        std::string getTag() override;

        void setParent(IElement *parent) override;

        IElement *getParent() override;

        Core::Application *getApplication() override;

        void setApplication(Core::Application *application) override;

        IElement *getChildByTag(std::string_view tag) override;

    protected:
        /**
         * Aplicacion a la que pertenece el elemento.
         */
        Core::Application *_application{nullptr};

        /**
         * Etiqueta del elemento.=
         */
        std::string _tag{};

        /**
         * Padre de este elemento.
         */
        IElement *_parent{nullptr};

        /**
         * Primero establece o remueve los padres de los elementos que se van a agregar o eliminar, respectivamente.
         * Luego, llama a la implementación de la clase base.
         */
        void handlePendingItemsOperations() override;
    };

} // Gui

#endif //BIBI_ELEMENT_HPP
