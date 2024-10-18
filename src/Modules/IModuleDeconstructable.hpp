//
// Created by packa on 9/10/2024.
//

#ifndef BIBI_IMODULEDECONSTRUCTABLE_HPP
#define BIBI_IMODULEDECONSTRUCTABLE_HPP

#define GLFW_INCLUDE_NONE
#include <glfw/glfw3.h>
#include "IModule.hpp"

namespace Bibi::Core {
    class Application;
}

namespace Bibi::Modules {
    class IModuleDeconstructable : public virtual IModule {
    public:
        ~IModuleDeconstructable() override = default;
        virtual void tearDown() = 0;
    };
} // Modules

#endif //BIBI_IMODULEDECONSTRUCTABLE_HPP
