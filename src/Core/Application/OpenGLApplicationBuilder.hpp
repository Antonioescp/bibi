//
// Created by packa on 8/10/2024.
//

#ifndef BIBI_OPENGLAPPLICATIONBUILDER_HPP
#define BIBI_OPENGLAPPLICATIONBUILDER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IApplicationBuilder.hpp"

namespace Bibi::Core::Application {

    class OpenGLApplicationBuilder : public IApplicationBuilder {
    public:
        IApplicationBuilder& setDimensions(int width, int height) override;
        IApplicationBuilder& setTitle(std::string title) override;
        Application build() override;
        IApplicationBuilder& addModule(std::unique_ptr<Module::IModule> module) override;

    private:
        int _width{ 640 };
        int _height{ 480 };
        std::string _title{ "Application" };
        std::vector<std::unique_ptr<Bibi::Module::IModule>> _modules;
    };

} // Application

#endif //BIBI_OPENGLAPPLICATIONBUILDER_HPP
