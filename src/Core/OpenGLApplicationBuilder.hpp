//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_OPENGLAPPLICATIONBUILDER_HPP
#define BIBI_OPENGLAPPLICATIONBUILDER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IApplicationBuilder.hpp"
#include "Module/IModuleConfigurable.hpp"
#include "Module/IModuleDeconstructable.hpp"
#include "Module/IModuleRunnable.hpp"

namespace Bibi::Core {

    class OpenGLApplicationBuilder : public IApplicationBuilder {
    public:
        IApplicationBuilder& setDimensions(int width, int height) override;
        IApplicationBuilder& setTitle(std::string title) override;
        IApplicationBuilder& addModule(std::unique_ptr<Module::IModule> module) override;
        Application build() override;

    private:
        int _width{ 640 };
        int _height{ 480 };
        std::string _title{ "Application" };
        std::vector<std::unique_ptr<Bibi::Module::IModule>> _modules;
    };

} // Application

#endif //BIBI_OPENGLAPPLICATIONBUILDER_HPP
