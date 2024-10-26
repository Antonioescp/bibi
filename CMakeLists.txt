cmake_minimum_required(VERSION 3.28)
project(bibi)

set(CMAKE_CXX_STANDARD 26)

add_executable(bibi main.cpp
        src/Core/Application.cpp
        src/Core/Application.hpp
        src/Core/IApplicationBuilder.hpp
        src/Core/OpenGLApplicationBuilder.cpp
        src/Core/OpenGLApplicationBuilder.hpp
        src/Modules/IModule.hpp
        src/Modules/Gui/ImGuiModule.cpp
        src/Modules/Gui/ImGuiModule.hpp
        src/Modules/Logging/LoggerModule.cpp
        src/Modules/Logging/LoggerModule.hpp
        src/Modules/Logging/Logger.cpp
        src/Modules/Logging/Logger.hpp
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
        src/Core/UI/ObjectListWindow.cpp
        src/Core/UI/ObjectListWindow.hpp
        src/Core/Object.cpp
        src/Core/Object.hpp
        src/Modules/Gui/Elements/TreeNodeElement.cpp
        src/Modules/Gui/Elements/TreeNodeElement.hpp
        src/Modules/Gui/Elements/ButtonElement.cpp
        src/Modules/Gui/Elements/ButtonElement.hpp
        src/Core/UI/InspectorWindow.cpp
        src/Core/UI/InspectorWindow.hpp
        src/Core/Component.cpp
        src/Core/Component.hpp
        src/Core/Lifecycle/ILifecycleAware.hpp
        src/Core/Lifecycle/DeferredCollection.hpp
        src/Core/Concepts/Pointer.hpp
        src/Core/Concepts/Lifecycle.hpp
        src/Modules/Logging/LoggerMixin.hpp
        src/Core/UI/InfoWindow.cpp
        src/Core/UI/InfoWindow.hpp
        src/Components/NameComponent.cpp
        src/Components/NameComponent.hpp
        src/Components/RenderComponent.cpp
        src/Components/RenderComponent.hpp
        src/Modules/Gui/Elements/ComponentElement.cpp
        src/Modules/Gui/Elements/ComponentElement.hpp
        src/Modules/Gui/Elements/LabelElement.cpp
        src/Modules/Gui/Elements/LabelElement.hpp
        src/Modules/Gui/Elements/SeparatorElement.cpp
        src/Modules/Gui/Elements/SeparatorElement.hpp
        src/Rendering/Mesh.cpp
        src/Rendering/Mesh.hpp
        src/Rendering/Shader.cpp
        src/Rendering/Shader.hpp
        src/Core/Enum.hpp
        src/Rendering/ShaderEnum.hpp
        src/Rendering/ShaderEnum.cpp
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

# Copying files to build directory
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG_BUILD)
endif()