//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULERUNNABLE_HPP
#define BIBI_IMODULERUNNABLE_HPP

#include <glfw/glfw3.h>
#include "IModule.hpp"

namespace Bibi::Module {

    class IModuleRunnable : public virtual IModule {
    public:
        ~IModuleRunnable() override = default;
        virtual void run(GLFWwindow* window) = 0;
    };

} // Module

#endif //BIBI_IMODULERUNNABLE_HPP
