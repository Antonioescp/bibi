//
// Created by packa on 25/10/2024.
//

#include "RenderComponent.hpp"
#include "Modules/Gui/Element.hpp"
#include "Core/Exceptions/Exception.hpp"

namespace Bibi::Components {
    void RenderComponent::setUp() {
        this->setName("Render");

        // setting up opengl buffers
        glGenBuffers(1, &_vbo);
        glGenVertexArrays(1, &_vao);

        _vertexShader.load();
        _vertexShader.compile();
        _fragmentShader.load();
        _fragmentShader.compile();

        _shaderProgram = glCreateProgram();
        glAttachShader(_shaderProgram, _vertexShader.getShaderId());
        glAttachShader(_shaderProgram, _fragmentShader.getShaderId());
        glLinkProgram(_shaderProgram);

        int success{};
        char infoLog[1024];
        glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(_shaderProgram, 1024, nullptr, infoLog);
            throw Core::Exceptions::Exception{infoLog};
        }

        glBindVertexArray(_vao);
        glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
        glBufferData(GL_ARRAY_BUFFER, this->mesh.vertices.size() * sizeof(*this->mesh.vertices.data()), this->mesh.vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
        glEnableVertexAttribArray(0);
        glBindVertexArray(0);
    }

    std::unique_ptr<Modules::Gui::IElement> RenderComponent::serializeToElement() {
        auto container{ std::make_unique<Modules::Gui::Element>() };

        return container;
    }

    void RenderComponent::update() {
        glUseProgram(_shaderProgram);

        // Drawing
        glUseProgram(_shaderProgram);
        glBindVertexArray(_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(_vao);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
} // Components
