//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_LOGGERMODULE_HPP
#define BIBI_LOGGERMODULE_HPP

#include "Modules/IModuleConfigurable.hpp"
#include "Modules/IModuleDeconstructable.hpp"

namespace Bibi::Modules::Logging {

    class LoggerModule : public IModuleConfigurable {
    public:
        void setUp() override;
    };

} // Logging

#endif //BIBI_LOGGERMODULE_HPP
