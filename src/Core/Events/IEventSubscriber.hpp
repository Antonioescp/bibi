//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_IEVENTSUBSCRIBER_HPP
#define BIBI_IEVENTSUBSCRIBER_HPP

#include <functional>

#include "Function.hpp"

namespace Bibi::Core::Events {

    template <class... TArguments>
    class IEventSubscriber {
    public:
        virtual ~IEventSubscriber() = default;
        virtual void subscribe(Function<TArguments...> callback) = 0;
        virtual void unsubscribe(Function<TArguments...> callback) = 0;
    };
}

#endif //BIBI_IEVENTSUBSCRIBER_HPP
