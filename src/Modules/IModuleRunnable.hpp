//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULERUNNABLE_HPP
#define BIBI_IMODULERUNNABLE_HPP

#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>
#include "IModule.hpp"

namespace Bibi::Modules {

    class IModuleRunnable : public virtual IModule {
    public:
        ~IModuleRunnable() override = default;
        virtual void run() = 0;
    };

} // Modules

#endif //BIBI_IMODULERUNNABLE_HPP
