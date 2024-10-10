//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_LOGGERMODULE_HPP
#define BIBI_LOGGERMODULE_HPP

#include "Module/IModuleConfigurable.hpp"
#include "Module/IModuleDeconstructable.hpp"

namespace Bibi::Module::Logging {

    class LoggerModule : public IModuleConfigurable  {
    public:
        void setUp(GLFWwindow* window) override;
    };

} // Logging

#endif //BIBI_LOGGERMODULE_HPP
