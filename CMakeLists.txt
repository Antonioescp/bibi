cmake_minimum_required(VERSION 3.28)
project(bibi)

set(CMAKE_CXX_STANDARD 26)

add_executable(bibi main.cpp
        src/Core/Application/Application.cpp
        src/Core/Application/Application.hpp
        src/Core/Application/IApplicationBuilder.hpp
        src/Core/Application/OpenGLApplicationBuilder.cpp
        src/Core/Application/OpenGLApplicationBuilder.hpp
)

find_package(glad CONFIG REQUIRED)
target_link_libraries(bibi PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(bibi PRIVATE glfw)