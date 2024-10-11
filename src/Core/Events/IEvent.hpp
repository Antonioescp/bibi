//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_IEVENT_HPP
#define BIBI_IEVENT_HPP

#include "IEventSubscriber.hpp"
#include "IEventPublisher.hpp"

namespace Bibi::Core::Events {

    template <class... TArguments>
    class IEvent : public IEventSubscriber<TArguments...>, public IEventPublisher<TArguments...> {
    public:
        virtual ~IEvent() = default;
    };

} // Events

#endif //BIBI_IEVENT_HPP
