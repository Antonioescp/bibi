//
// Created by packa on 10/10/2024.
//

#ifndef BIBI_EXCEPTION_HPP
#define BIBI_EXCEPTION_HPP

#include <exception>
#include <stacktrace>
#include <source_location>
#include <utility>

namespace Bibi::Core::Exceptions {

    /**
     * Clase para las excepciones de la aplicación.
     * Contiene la traza de la pila y la ubicación del error.
     * @note esta clase debe ser heredada para crear excepciones específicas.
     */
    class Exception : public std::exception {
    public:

        /**
         * Crea una instancia de Exception.
         * @param message Un mensaje explicativo del error.
         * @param stacktrace La pila de llamadas al momento de la excepción.
         * @param location La ubicación del error.
         */
        explicit Exception(
                const char *message,
                std::stacktrace stacktrace = std::stacktrace::current(),
                std::source_location location = std::source_location::current())
                : std::exception(message), _stacktrace(std::move(stacktrace)), _location(location) {
        }

        /**
         * Devuelve la traza de la pila.
         * @return Traza de la pila de llamadas.
         */
        [[nodiscard]] const std::stacktrace &stacktrace() const;

        /**
         * Devuelve la ubicación del error.
         * @return Ubicación del error en el código fuente.
         */
        [[nodiscard]] const std::source_location &location() const;

    private:
        // Pila de llamadas
        std::stacktrace _stacktrace;

        // Ubicación del error en código fuente
        std::source_location _location;
    };

} // Exceptions

#endif //BIBI_EXCEPTION_HPP
