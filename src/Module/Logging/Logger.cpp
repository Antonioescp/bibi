//
// Created by packa on 9/10/2024.
//

#include <iostream>
#include <spdlog/cfg/env.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

#include "Logger.hpp"

namespace Bibi::Module::Logging {
    const std::string Logger::_coreLogName{"core"};
    const std::string Logger::_pattern{"[%Y-%m-%d %H:%M:%S.%e] [%n] [%^%l%$] %v"};
    bool Logger::_initialized{false};

    void Logger::initialize() {
        if (_initialized) {
            spdlog::warn("Logger already initialized");
            return;
        }

        try {
            spdlog::cfg::load_env_levels();

            auto consoleSink{createConsoleSink(_coreLogName)};
            auto dailySink{createDailyFileSink(_coreLogName)};

            spdlog::sinks_init_list sinks{consoleSink, dailySink};
            auto logger{createLogger(_coreLogName, sinks)};
            spdlog::set_default_logger(logger);

            spdlog::info("Logger initialized");

            _initialized = true;
        }
        catch (const spdlog::spdlog_ex &ex) {
            std::cerr << "Log initialization failed: " << ex.what() << std::endl;
            std::exit(1);
        }
    }

    std::shared_ptr<spdlog::logger> Logger::createDailyFileLogger(const std::string &name) {
        try {
            auto consoleSink{createConsoleSink(name)};
            auto dailySink{createDailyFileSink(name)};

            spdlog::sinks_init_list sinks{consoleSink, dailySink};
            auto logger{createLogger(name, sinks)};

            spdlog::info("Logger created: {}", name);

            return logger;
        }
        catch (const spdlog::spdlog_ex &ex) {
            std::cerr << "Logger creation failed: " << ex.what() << std::endl;
            return nullptr;
        }
    }

    std::shared_ptr<spdlog::logger> Logger::get(const std::string &name) {
        auto existingLogger{spdlog::get(name)};
        return existingLogger ? existingLogger : createDailyFileLogger(name);
    }

    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> Logger::createConsoleSink(const std::string &name) {
        auto consoleSink{std::make_shared<spdlog::sinks::stdout_color_sink_mt>()};
        consoleSink->set_level(spdlog::level::debug);
        consoleSink->set_pattern(_pattern);

        return consoleSink;
    }

    std::shared_ptr<spdlog::sinks::daily_file_sink_mt> Logger::createDailyFileSink(const std::string &name) {
        auto dailySink{std::make_shared<spdlog::sinks::daily_file_sink_mt>(name + ".log", 23, 59)};
        dailySink->set_level(spdlog::level::debug);
        dailySink->set_pattern(_pattern);

        return dailySink;
    }

    std::shared_ptr<spdlog::logger> Logger::createLogger(const std::string &name, spdlog::sinks_init_list &sinks) {
        auto logger{std::make_shared<spdlog::logger>(name, sinks.begin(), sinks.end())};
        spdlog::register_logger(logger);

        return logger;
    }
} // Logging