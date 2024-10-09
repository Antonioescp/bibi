#include <iostream>

#include "src/Core/Application/OpenGLApplicationBuilder.hpp"
#include "src/Core/Application/Application.hpp"
#include "Module/ImGuiModule.hpp"
#include "Module/Logging/LogModule.hpp"

using namespace Bibi::Core::Application;

int main() {
    OpenGLApplicationBuilder appBuilder{};
    appBuilder
            .setDimensions(1920, 1080)
            .setTitle("Bibi Engine")
            .addModule(std::make_unique<Bibi::Module::Logging::LogModule>())
            .addModule(std::make_unique<Bibi::Module::ImGuiModule>());

    auto app{ appBuilder.build() };
    app.run();
}
