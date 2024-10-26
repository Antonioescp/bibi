//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_LOGGERMODULE_HPP
#define BIBI_LOGGERMODULE_HPP

#include "Modules/IModule.hpp"

namespace Bibi::Modules::Logging {

    /**
     * Módulo de logging, se encarga de inicializar el logger principal de la aplicación.
     */
    class LoggerModule : public IModule {
    public:
        LoggerModule() = default;

        /**
         * Crea el logger "core", es el principal de la aplicación y el que se debe utilizar
         * para logs generales.
         */
        void setUp() override;
    };

} // Logging

#endif //BIBI_LOGGERMODULE_HPP
