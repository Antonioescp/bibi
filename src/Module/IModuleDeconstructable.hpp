//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULEDECONSTRUCTABLE_HPP
#define BIBI_IMODULEDECONSTRUCTABLE_HPP

#include <glfw/glfw3.h>
#include "IModule.hpp"

namespace Bibi::Core {
    class Application;
}

namespace Bibi::Module {
    class IModuleDeconstructable : public virtual IModule {
    public:
        ~IModuleDeconstructable() override = default;
        virtual void tearDown(GLFWwindow* window) = 0;
    };
} // Module

#endif //BIBI_IMODULEDECONSTRUCTABLE_HPP
