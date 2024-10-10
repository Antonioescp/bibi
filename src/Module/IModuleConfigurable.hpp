//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULECONFIGURABLE_HPP
#define BIBI_IMODULECONFIGURABLE_HPP

#include <glfw/glfw3.h>
#include "IModule.hpp"

namespace Bibi::Module {

    class IModuleConfigurable : public virtual IModule {
    public:
        ~IModuleConfigurable() override = default;
        virtual void setUp(GLFWwindow* window) = 0;
    };

} // Module

#endif //BIBI_IMODULECONFIGURABLE_HPP
