//
// Created by packa on 21/10/2024.
//

#ifndef BIBI_DEFERREDCOLLECTION_HPP
#define BIBI_DEFERREDCOLLECTION_HPP

#include <vector>
#include <concepts>
#include <memory>
#include "ILifecycleAware.hpp"
#include "Core/Concepts/Lifecycle.hpp"

namespace Bibi::Core::Lifecycle {

    /**
     * Colección de objetos que implementan el ciclo de vida.
     * @tparam TItem Tipo de los objetos que contiene.
     * @note TItem debe implementar la interfaz ILifecycleAware.
     * @note Los objetos se añaden y eliminan en el siguiente ciclo de vida.
     */
    template <typename TItem>
    requires std::derived_from<TItem, ILifecycleAware>
    class DeferredCollection : public virtual ILifecycleAware {
    public:
        /**
         * Procesa las operaciones pendientes de agregar o remover un elemento de la colección
         * y ejecuta la operación de setUp en cada elemento de la colección.
         */
        void setUp() override {
            handlePendingItemsOperations();
        }

        /**
         * Procesa las operaciones pendientes de agregar o remover un elemento de la colección
         * y ejecuta la operación de update en cada elemento de la colección.
         */
        void update() override {
            for (auto& item : _items) {
                item->update();
            }
            handlePendingItemsOperations();
        }

        /**
         * Procesa las operaciones pendientes de agregar o remover un elemento de la colección
         * y ejecuta la operación de tearDown en cada elemento de la colección.
         */
        void tearDown() override {
            handlePendingItemsOperations();
            for (auto& item : _items) {
                item->tearDown();
            }
        }

        /**
         * Agrega un elemento a la colección.
         * @param item El elemento a agregar.
         * @note El objeto se añadirá en el siguiente ciclo de vida.
         */
        void add(std::unique_ptr<TItem> item) {
            _itemsToAdd.push_back(std::move(item));
        }

        /**
         * Elimina un elemento de la colección.
         * @param item El elemento a eliminar.
         * @note El objeto se eliminará en el siguiente ciclo de vida.
         */
        void remove(TItem* item) {
            _itemsToRemove.push_back(item);
        }

        /**
         * Obtiene un iterador al principio de la colección.
         * @return Iterador al principio de la colección.
         */
        auto begin() {
            return _items.begin();
        }

        /**
         * Obtiene un iterador al final de la colección.
         * @return Iterador al final de la colección.
         */
        auto end() {
            return _items.end();
        }

        [[nodiscard]] std::size_t size() const {
            return _items.size();
        }

        const std::vector<std::unique_ptr<TItem>>& getPendingToAdd() const {
            return _itemsToAdd;
        }

        const std::vector<TItem*>& getPendingToRemove() const {
            return _itemsToRemove;
        }

        void clear() {
            for (auto& item : _items) {
                this->remove(item.get());
            }
        }

        void clearWithoutLifecycle() {
            _items.clear();
            _itemsToAdd.clear();
            _itemsToRemove.clear();
        }

    protected:
        /**
         * Coleccion de objetos que implementan el ciclo de vida.
         */
        std::vector<std::unique_ptr<TItem>> _items;

        /**
         * Coleccion de objetos a agregar en el siguiente ciclo de vida.
         */
        std::vector<std::unique_ptr<TItem>> _itemsToAdd;

        /**
         * Coleccion de objetos a eliminar en el siguiente ciclo de vida.
         */
        std::vector<TItem*> _itemsToRemove;

        /**
         * Realiza las operaciones pendientes de añadir y eliminar objetos.
         * @note Este método debe ser llamado en cada ciclo de vida.
         */
        virtual void handlePendingItemsOperations() {
            for (auto& item : _itemsToAdd) {
                // Se asegura de que esté en la colección antes de llamar a setUp
                auto itemPtr = item.get();
                _items.push_back(std::move(item));

                itemPtr->setUp();
            }
            _itemsToAdd.clear();

            for (auto& item : _itemsToRemove) {
                item->tearDown();

                std::erase_if(_items, [item](const std::unique_ptr<TItem>& i) {
                    return i.get() == item;
                });
            }
            _itemsToRemove.clear();
        }
    };

} // Lifecycle

#endif //BIBI_DEFERREDCOLLECTION_HPP
