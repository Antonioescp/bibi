//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_LOGGER_HPP
#define BIBI_LOGGER_HPP

#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

namespace Bibi::Module::Logging {

    class Logger {
    public:
        static void initialize();
        static std::shared_ptr<spdlog::logger> createDailyFileLogger(const std::string& name);
        static std::shared_ptr<spdlog::logger> getLogger(const std::string& name);

    private:
        static const std::string _coreLogName;
        static const std::string _pattern;
        static bool _initialized;

        static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> createConsoleSink(const std::string& name);
        static std::shared_ptr<spdlog::sinks::daily_file_sink_mt> createDailyFileSink(const std::string& name);
        static std::shared_ptr<spdlog::logger> createLogger(const std::string& name, spdlog::sinks_init_list& sinks);
    };

} // Logging

#endif //BIBI_LOGGER_HPP
