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
         * Se realizan todas las configuraciones necesarias para el elemento.
         * @note IMPORTANTE: Llamar a la implementación base de este método Element::setUp() en las clases
         * derivadas para asegurar que los elementos hijos sean configurados adecuadamente.
         * @note Aquí se pueden agregar elementos hijos, configurar el elemento, etc.
         * @note Se recomienda llamar Element::setUp() al final de la implementación de este método en las clases derivadas.
         */
        void setUp() override;

        /**
         * Se actualiza el elemento, utilice este método para renderizar el elemento.
         * @note IMPORTANTE: Llamar a la implementación base de este método Element::update() en las clases
         * derivadas para asegurar que los elementos hijos sean actualizados adecuadamente. Este método
         * se puede llamar donde considere adecuado para renderizar los elementos hijos.
         */
        void update() override;

        /**
         * Se realiza la limpieza de los recursos utilizados por el elemento.
         * @note IMPORTANTE: Llamar a la implementación base de este método Element::tearDown() en las clases
         * derivadas para asegurar que los elementos hijos sean limpiados adecuadamente.
         * @note Se recomienda llamar Element::tearDown() al inicio de la implementación de este método en las clases derivadas.
         */
        void tearDown() override;

        /**
         * Agrega un elemento hijo a este elemento.
         * @param element El elemento hijo a agregar.
         * @note El elemento hijo será adecuadamente administrado por el elemento padre.
         * @note El elemento se agrega de manera diferida, es decir, se agrega al inicio del siguiente ciclo de actualización.
         */
        void addElement(std::unique_ptr<IElement> element) override;

        /**
         * Elimina un elemento hijo de este elemento.
         * @param element El elemento hijo a eliminar.
         * @note El elemento se elimina de manera diferida, es decir, se elimina al inicio del siguiente ciclo de actualización.
         */
        void removeElement(IElement *element) override;

        /**
         * Elimina todos los elementos hijos de este elemento que tengan una etiqueta específica.
         * @param tag La etiqueta de los elementos a eliminar.
         * @note Los elementos se eliminan de manera diferida, es decir, se eliminan al inicio del siguiente ciclo de actualización.
         */
        void removeElements(std::string tag) override;

        /**
         * Elimina todos los elementos hijos de este elemento que sean del tipo especificado.
         * @tparam TElement El tipo de elemento a eliminar.
         * @note Los elementos se eliminan de manera diferida, es decir, se eliminan al inicio del siguiente ciclo de actualización.
         */
        template <typename TElement>
        requires std::derived_from<TElement, IElement>
        void removeElements() {
            for (auto &element : _childrenElements) {
                if (dynamic_cast<TElement*>(element.get())) {
                    _elementsToRemove.push_back(element.get());
                }
            }
        }

        void clearElements() override;

        std::vector<std::unique_ptr<IElement>> &getElements() override;

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
         * Coleccion de todos los elementos hijos de este elemento.
         */
        std::vector<std::unique_ptr<IElement>> _childrenElements{};

        /**
         * Coleccion de elementos hijos que se van a agregar en el siguiente ciclo de actualizacion.
         */
        std::vector<std::unique_ptr<IElement>> _elementsToAdd{};

        /**
         * Coleccion de elementos hijos que se van a eliminar en el siguiente ciclo de actualizacion.
         */
        std::vector<IElement*> _elementsToRemove{};

        /**
         * Etiqueta del elemento.=
         */
        std::string _tag{};

        /**
         * Padre de este elemento.
         */
        IElement *_parent{nullptr};

        /**
         * Maneja los elementos pendientes de agregar y eliminar.
         * @note se llama en Element::setUp() y antes de iniciar la actualizacion de los elementos en Element::update().
         */
        void handlePendingElements();
    };

} // Gui

#endif //BIBI_ELEMENT_HPP
