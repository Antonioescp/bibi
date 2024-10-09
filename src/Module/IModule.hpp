//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULE_HPP
#define BIBI_IMODULE_HPP

namespace Bibi::Module {
    class IModule {
    public:
        virtual ~IModule() = default;
        virtual void setUp() = 0;
        virtual void tearDown() = 0;
        virtual void run() = 0;
    };
} // Module

#endif //BIBI_IMODULE_HPP
