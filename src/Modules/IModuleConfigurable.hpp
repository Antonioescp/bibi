//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULECONFIGURABLE_HPP
#define BIBI_IMODULECONFIGURABLE_HPP

#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>
#include "IModule.hpp"

namespace Bibi::Modules {

    class IModuleConfigurable : public virtual IModule {
    public:
        ~IModuleConfigurable() override = default;
        virtual void setUp() = 0;
    };

} // Modules

#endif //BIBI_IMODULECONFIGURABLE_HPP
