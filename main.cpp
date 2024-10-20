#include "Core/OpenGLApplicationBuilder.hpp"
#include "Core/Application.hpp"
#include "Modules/Gui/ImGuiModule.hpp"
#include "Modules/Logging/LoggerModule.hpp"
#include "Core/Exceptions/Exception.hpp"

using namespace Bibi::Core;
using namespace Bibi::Modules;
using namespace Exceptions;

int main() {
    try {
        OpenGLApplicationBuilder appBuilder{};

        appBuilder
                .setDimensions(1920, 1080)
                .setTitle("Bibi Engine")
                .addModule(std::make_unique<Logging::LoggerModule>())
                .addModule(std::make_unique<Gui::ImGuiModule>());

        auto app{ appBuilder.build() };
        app.run();
    }
    catch (Bibi::Core::Exceptions::Exception& exception) {
        Logging::Logger::initialize();
        auto logger{ Logging::Logger::get("core") };
        auto& location{ exception.location() };
        logger->error("[{}][{}] An error occurred: {}", location.file_name(), location.line(), exception.what());
        logger->error("Stacktrace:");
        for (const auto& entry : exception.stacktrace()) {
            logger->error("{}", entry.description());
        }
        return 1;
    }
    catch (std::exception& exception) {
        Logging::Logger::initialize();
        auto logger{ Logging::Logger::get("core") };
        logger->error("An error occurred: {}", exception.what());
        return 1;
    }
}
