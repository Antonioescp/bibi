//
// Created by packa on 26/10/2024.
//

#include <filesystem>
#include <fstream>
#include <sstream>
#include "Shader.hpp"

namespace Bibi::Rendering {
    Shader::Shader(const ShaderEnum &kind, std::string filePath) : _shaderKind{kind},
                                                                   _shaderFilePath{std::move(filePath)} {
    }

    void Shader::load() {
        using namespace std::filesystem;
        using namespace std;

        path filePath{_shaderFilePath};
        ifstream file{filePath, ios_base::in};

        stringstream stringStream{};
        stringStream << file.rdbuf();

        _shaderSource = stringStream.str();
    }

    const char *Shader::getLoggerName() {
        return "rendering";
    }

    void Shader::compile() {
        _shaderId = glCreateShader(_shaderKind.getValue());
        const auto *source{_shaderSource.data()};
        glShaderSource(_shaderId, 1, &source, nullptr);
        glCompileShader(_shaderId);

        this->errorCheck();
    }

    void Shader::errorCheck() const {
        int success;
        char infoLog[1024];

        glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(_shaderId, 512, nullptr, infoLog);
            _logger->error("Error de compilación en shader de tipo {}, para archivo {}: {}", _shaderKind.getName(),
                           _shaderFilePath, infoLog);
            return;
        }

        _logger->info("Shader {} de archivo {} compilado con exito", _shaderKind.getName(), _shaderFilePath);
    }

    unsigned int Shader::getShaderId() const {
        return _shaderId;
    }
} // Rendering
// Bibi