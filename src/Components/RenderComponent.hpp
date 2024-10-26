//
// Created by packa on 25/10/2024.
//

#ifndef BIBI_RENDERCOMPONENT_HPP
#define BIBI_RENDERCOMPONENT_HPP

#include "Core/Component.hpp"
#include "Rendering/Mesh.hpp"
#include "Rendering/Shader.hpp"

namespace Bibi::Components {

    class RenderComponent : public virtual Core::Component {
    public:
        using Core::Component::Component;

        void setUp() override;
        void update() override;
        std::unique_ptr<Modules::Gui::IElement> serializeToElement() override;

    private:
        Rendering::Mesh mesh{};
        Rendering::Shader _vertexShader{Rendering::ShaderEnum::VERTEX_SHADER, "data/shaders/simple.vert" };
        Rendering::Shader _fragmentShader{Rendering::ShaderEnum::FRAGMENT_SHADER, "data/shaders/simple.frag" };
        unsigned int _vbo{};
        unsigned int _vao{};
        unsigned int _shaderProgram{};
    };

} // Components

#endif //BIBI_RENDERCOMPONENT_HPP
