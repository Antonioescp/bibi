//
// Created by packa on 21/10/2024.
//

#ifndef BIBI_LOGGERMIXIN_HPP
#define BIBI_LOGGERMIXIN_HPP

#include <spdlog/spdlog.h>
#include "Modules/Logging/Logger.hpp"

namespace Bibi::Modules::Logging {

    template <class T>
    class LoggerMixin {
    public:
        virtual ~LoggerMixin() = default;

    protected:
        std::shared_ptr<spdlog::logger> _logger{ Logger::get(dynamic_cast<T*>(this)->getLoggerName()) };
    };

} // Logging

#endif //BIBI_LOGGERMIXIN_HPP
