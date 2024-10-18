cmake_minimum_required(VERSION 3.28)
project(bibi)

set(CMAKE_CXX_STANDARD 26)

add_executable(bibi main.cpp
        src/Core/Application.cpp
        src/Core/Application.hpp
        src/Core/IApplicationBuilder.hpp
        src/Core/OpenGLApplicationBuilder.cpp
        src/Core/OpenGLApplicationBuilder.hpp
        src/Modules/IModuleConfigurable.hpp
        src/Modules/IModule.hpp
        src/Modules/Gui/ImGuiModule.cpp
        src/Modules/Gui/ImGuiModule.hpp
        src/Modules/Logging/LoggerModule.cpp
        src/Modules/Logging/LoggerModule.hpp
        src/Modules/Logging/Logger.cpp
        src/Modules/Logging/Logger.hpp
        src/Modules/IModuleDeconstructable.hpp
        src/Modules/IModuleRunnable.hpp
        src/Modules/Gui/IElement.hpp
        src/Modules/Gui/Elements/MainMenuBarElement.cpp
        src/Modules/Gui/Elements/MainMenuBarElement.hpp
        src/Core/Events/Event.hpp
        src/Core/Events/IEventSubscriber.hpp
        src/Core/Events/IEventPublisher.hpp
        src/Core/Events/IEvent.hpp
        src/Core/Exceptions/Exception.cpp
        src/Core/Exceptions/Exception.hpp
        src/Core/Events/Function.hpp
        src/Modules/Gui/Element.cpp
        src/Modules/Gui/Element.hpp
        src/Modules/Gui/Elements/MenuElement.cpp
        src/Modules/Gui/Elements/MenuElement.hpp
        src/Modules/Gui/Elements/MenuItemElement.cpp
        src/Modules/Gui/Elements/MenuItemElement.hpp
        src/Modules/Gui/Elements/WindowElement.cpp
        src/Modules/Gui/Elements/WindowElement.hpp
        src/Core/UI/BibiMainMenuElement.cpp
        src/Core/UI/BibiMainMenuElement.hpp
        src/Core/UI/ElementTag.cpp
        src/Core/UI/ElementTag.hpp
        src/Core/UI/BibiAboutWindowElement.cpp
        src/Core/UI/BibiAboutWindowElement.hpp
        src/Modules/Gui/Elements/TextElement.cpp
        src/Modules/Gui/Elements/TextElement.hpp
)

target_include_directories(bibi PRIVATE src)

find_package(glad CONFIG REQUIRED)
target_link_libraries(bibi PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(bibi PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(bibi PRIVATE imgui::imgui)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(bibi PRIVATE spdlog::spdlog)

# Define the source directory and the destination directory (bin dir)
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/data")
set(DEST_DIR "${CMAKE_BINARY_DIR}")

# Copy the directory from source to bin
file(COPY ${SOURCE_DIR} DESTINATION ${DEST_DIR})