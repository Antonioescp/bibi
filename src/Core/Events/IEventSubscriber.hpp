//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_IEVENTSUBSCRIBER_HPP
#define BIBI_IEVENTSUBSCRIBER_HPP

#include <functional>

#include "Function.hpp"

namespace Bibi::Core::Events {

    /**
     * Interfaz de suscriptor de eventos.
     * @note Utilice esta interfaz para suscribirse o desuscribirse de eventos.
     * @tparam TArguments Los argumentos a manejar en el evento.
     */
    template <class... TArguments>
    class IEventSubscriber {
    public:
        virtual ~IEventSubscriber() = default;

        /**
         * Suscribirse a un evento.
         * @param callback Acción a realizar cuando se dispare el evento.
         */
        virtual void subscribe(Function<TArguments...> callback) = 0;

        /**
         * Desuscribirse de un evento.
         * @param callback Acción a desuscribir del evento.
         * @note La acción ya no se ejecutará cuando se dispare el evento.
         */
        virtual void unsubscribe(Function<TArguments...> callback) = 0;
    };
}

#endif //BIBI_IEVENTSUBSCRIBER_HPP
