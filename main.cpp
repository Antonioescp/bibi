#include <iostream>

#include "src/Core/Application/OpenGLApplicationBuilder.hpp"
#include "src/Core/Application/Application.hpp"

using namespace Bibi::Core::Application;

int main() {
    OpenGLApplicationBuilder appBuilder{};
    appBuilder
        .setDimensions(1920, 1080)
        .setTitle("Bibi Engine");

    auto app{ appBuilder.build() };
    app.Run();
}
