//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_LOGGER_HPP
#define BIBI_LOGGER_HPP

#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

namespace Bibi::Modules::Logging {

    /**
     * Clase para administrar los logs de la aplicación.
     */
    class Logger {
    public:
        Logger() = delete;

        /**
         * Inicializa el sistema de logs.
         * Se llama automáticamente al inicio de la aplicación.
         * @note No es necesario llamar a este método manualmente.
         * @ref Logger::get
         */
        static void initialize();

        /**
         * Obtiene un logger existente o lo crea si no existe.
         * @param name Nombre del logger a obtener.
         * @return El logger obtenido.
         */
        static std::shared_ptr<spdlog::logger> get(const std::string& name);

    private:
        /**
         * Nombre de logger general de la aplicación.
         */
        static const std::string _coreLogName;

        /**
         * Patrón de formato de los logs.
         */
        static const std::string _pattern;

        /**
         * Indica si el sistema de logs ya fue inicializado.
         */
        static bool _initialized;

        /**
         * Crea un sink para escribir en la consola.
         * @param name Nombre del sink.
         * @return El sink para escribir en la consola.
         */
        static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> createConsoleSink(const std::string& name);

        /**
         * Crea un sink y del archivo para escribir en un archivo diario.
         * @param name Nombre del sink.
         * @return El sink para escribir en un archivo diario.
         */
        static std::shared_ptr<spdlog::sinks::daily_file_sink_mt> createDailyFileSink(const std::string& name);

        /**
         * Crea un logger que escribe en la consola y en un archivo diario.
         * @param name Nombre del logger.
         * @return El nuevo logger para escribir en consola y archivo diario.
         */
        static std::shared_ptr<spdlog::logger> createDailyFileLogger(const std::string& name);

        /**
         * Crea un logger con los sinks especificados.
         * @param name Nombre del logger.
         * @param sinks Los sinks a utilizar.
         * @return El logger con los sinks especificados.
         */
        static std::shared_ptr<spdlog::logger> createLogger(const std::string& name, spdlog::sinks_init_list& sinks);
    };

} // Logging

#endif //BIBI_LOGGER_HPP
