#include <iostream>

#include "Core/OpenGLApplicationBuilder.hpp"
#include "Core/Application.hpp"
#include "Module/Gui/ImGuiModule.hpp"
#include "Module/Logging/LoggerModule.hpp"

using namespace Bibi::Core;
using namespace Bibi::Module;

int main() {
    OpenGLApplicationBuilder appBuilder{};

    appBuilder
            .setDimensions(1920, 1080)
            .setTitle("Bibi Engine")
            .addModule(std::make_unique<Logging::LoggerModule>())
            .addModule(std::make_unique<Gui::ImGuiModule>());

    auto app{ appBuilder.build() };
    app.run();
}
