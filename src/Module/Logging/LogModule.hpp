//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_LOGMODULE_HPP
#define BIBI_LOGMODULE_HPP


#include "Module/IModule.hpp"

namespace Bibi::Module::Logging {

    class LogModule : public IModule {
    public:
        void setUp() override;

        void tearDown() override;

        void run() override;
    };

} // Logging

#endif //BIBI_LOGMODULE_HPP
