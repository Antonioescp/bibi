cmake_minimum_required(VERSION 3.28)
project(bibi)

set(CMAKE_CXX_STANDARD 26)

add_executable(bibi main.cpp
        src/Core/Application.cpp
        src/Core/Application.hpp
        src/Core/IApplicationBuilder.hpp
        src/Core/OpenGLApplicationBuilder.cpp
        src/Core/OpenGLApplicationBuilder.hpp
        src/Module/IModuleConfigurable.hpp
        src/Module/IModule.hpp
        src/Module/Gui/ImGuiModule.cpp
        src/Module/Gui/ImGuiModule.hpp
        src/Module/Logging/LoggerModule.cpp
        src/Module/Logging/LoggerModule.hpp
        src/Module/Logging/Logger.cpp
        src/Module/Logging/Logger.hpp
        src/Module/IModuleDeconstructable.hpp
        src/Module/IModuleRunnable.hpp
        src/Module/Gui/IElement.hpp
        src/Module/Gui/Elements/MainMenuBarElement.cpp
        src/Module/Gui/Elements/MainMenuBarElement.hpp
        src/Core/Events/Event.hpp
        src/Core/Events/IEventSubscriber.hpp
        src/Core/Events/IEventPublisher.hpp
        src/Core/Events/IEvent.hpp
        src/Core/Exceptions/Exception.cpp
        src/Core/Exceptions/Exception.hpp
        src/Core/Events/Function.hpp
        src/Module/Gui/Element.cpp
        src/Module/Gui/Element.hpp
        src/Module/Gui/Elements/MenuElement.cpp
        src/Module/Gui/Elements/MenuElement.hpp
        src/Module/Gui/Elements/MenuItemElement.cpp
        src/Module/Gui/Elements/MenuItemElement.hpp
        src/Module/Gui/Elements/WindowElement.cpp
        src/Module/Gui/Elements/WindowElement.hpp
        src/Core/UI/BibiMainMenuElement.cpp
        src/Core/UI/BibiMainMenuElement.hpp
        src/Core/UI/ElementTag.cpp
        src/Core/UI/ElementTag.hpp
        src/Core/UI/BibiAboutWindowElement.cpp
        src/Core/UI/BibiAboutWindowElement.hpp
        src/Module/Gui/Elements/TextElement.cpp
        src/Module/Gui/Elements/TextElement.hpp
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