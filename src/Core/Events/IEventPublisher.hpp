//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_IEVENTPUBLISHER_HPP
#define BIBI_IEVENTPUBLISHER_HPP

namespace Bibi::Core::Events {
    template <class... TArguments>
    class IEventPublisher {
    public:
        virtual ~IEventPublisher() = default;
        virtual void trigger(TArguments... arguments) = 0;
    };
}

#endif //BIBI_IEVENTPUBLISHER_HPP
