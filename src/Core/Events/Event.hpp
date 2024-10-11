//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_EVENT_HPP
#define BIBI_EVENT_HPP

#include <vector>
#include "IEvent.hpp"

namespace Bibi::Core::Events {

    template<class... TArguments>
    class Event : public IEvent<TArguments...> {
    public:
        Event() = default;

        void trigger(TArguments... arguments) override {
            for (auto &callback: _callbacks) {
                callback(std::forward<TArguments>(arguments)...);
            }
        }

        void subscribe(Function<TArguments...> callback) override {
            _callbacks.push_back(callback);
        }

        void unsubscribe(Function<TArguments...> callback) override {
            _callbacks.erase(std::remove(_callbacks.begin(), _callbacks.end(), callback), _callbacks.end());
        }

        void clear() {
            _callbacks.clear();
        }

        size_t subscribersCount() {
            return _callbacks.size();
        }

    private:
        std::vector<Function<TArguments...>> _callbacks;
    };

} // Events

#endif //BIBI_EVENT_HPP
