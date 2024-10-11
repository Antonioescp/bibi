//
// Created by packa on 11/10/2024.
//

#ifndef BIBI_FUNCTION_HPP
#define BIBI_FUNCTION_HPP

#include <string>
#include <functional>
#include <chrono>
#include <thread>

namespace Bibi::Core::Events {
    template<class... TArguments>
    class Function : public std::function<void(TArguments...)> {
    public:
        using std::function<void(TArguments...)>::function;
        virtual ~Function() = default;

        bool operator==(const Function& other) {
            return _id == other._id;
        }

    private:
        std::string _id{ generateUniqueId() };

        static std::string generateUniqueId() {
            auto timeNow = std::chrono::system_clock::now();
            auto durationNowSinceEpoch = timeNow.time_since_epoch();
            auto durationNowNano = std::chrono::duration_cast<std::chrono::nanoseconds>(durationNowSinceEpoch);

            auto threadId = std::hash<std::thread::id>{}(std::this_thread::get_id());
            return std::to_string(durationNowNano.count()) + std::to_string(threadId);
        }
    };
}

#endif //BIBI_FUNCTION_HPP
