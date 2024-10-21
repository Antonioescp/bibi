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

    /**
     * Clase para generar std::function con un id único para cada instancia,
     * el unico proposito de esta clase es poder comparar instancias de std::function.
     * @tparam TArguments Argumentos de la función.
     * @note Esta clase solo acepta funciones que retornen void.
     * @note Esta solo tiene el propocito de ser utilizada con los eventos.
     */
    template<class... TArguments>
    class Function : public std::function<void(TArguments...)> {
    public:
        // Utilizar constructores de std::function.
        using std::function<void(TArguments...)>::function;
        virtual ~Function() = default;

        /**
         * Sobrecarga del operador == para comparar instancias de Function.
         * @param other Otra instancia de Function.
         * @return true si las instancias son iguales, false en caso contrario.
         */
        bool operator==(const Function& other) {
            return _id == other._id;
        }

    private:
        // Id único de la instancia.
        std::string _id{ generateUniqueId() };

        /**
         * Genera un id único para la instancia basado en el tiempo en nano segundos y el id del hilo.
         * @return Una cadena de texto con el id único.
         */
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
