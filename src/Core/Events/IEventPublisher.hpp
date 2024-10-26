//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_IEVENTPUBLISHER_HPP
#define BIBI_IEVENTPUBLISHER_HPP

namespace Bibi::Core::Events {

    /**
     * Interfaz que define un publicador de eventos.
     * @tparam TArguments Argumentos que se pasan al evento.
     * @note Utilice esta clase para definir un publicador de eventos.
     */
    template <class... TArguments>
    class IEventPublisher {
    public:
        virtual ~IEventPublisher() = default;

        /**
         * Dispara el evento.
         * @param arguments Los argumentos que se pasan al evento.
         * @note Este método se utiliza para ejecutar todas las acciones asociadas al evento.
         */
        virtual void trigger(TArguments... arguments) = 0;
    };
}

#endif //BIBI_IEVENTPUBLISHER_HPP
