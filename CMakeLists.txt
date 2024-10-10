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
        src/Module/ImGui/ImGuiModule.cpp
        src/Module/ImGui/ImGuiModule.hpp
        src/Module/Logging/LoggerModule.cpp
        src/Module/Logging/LoggerModule.hpp
        src/Module/Logging/Logger.cpp
        src/Module/Logging/Logger.hpp
        src/Module/IModuleDeconstructable.hpp
        src/Module/IModuleRunnable.hpp
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