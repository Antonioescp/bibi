//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_IAPPLICATIONBUILDER_HPP
#define BIBI_IAPPLICATIONBUILDER_HPP

#include <string>

#include "Application.hpp"
#include "Module/IModule.hpp"

namespace Bibi::Core::Application {

    class IApplicationBuilder {
    public:
        virtual IApplicationBuilder& setDimensions(int width, int height) = 0;
        virtual IApplicationBuilder& setTitle(std::string title) = 0;
        virtual IApplicationBuilder& addModule(std::unique_ptr<Module::IModule> module) = 0;
        virtual Application build() = 0;
    };

} // Application

#endif //BIBI_IAPPLICATIONBUILDER_HPP
