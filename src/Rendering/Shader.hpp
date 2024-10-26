//
// Created by packa on 26/10/2024.
//

#ifndef BIBI_SHADER_HPP
#define BIBI_SHADER_HPP

#include <string_view>
#include "Rendering/ShaderEnum.hpp"
#include "Modules/Logging/LoggerMixin.hpp"

namespace Bibi::Rendering {

    class Shader : public Modules::Logging::LoggerMixin<Shader> {
    public:
        Shader(const Rendering::ShaderEnum& kind, std::string filePath);
        void load();
        void compile();

        [[nodiscard]] unsigned int getShaderId() const;

        static const char* getLoggerName();

    private:
        const Rendering::ShaderEnum& _shaderKind;
        std::string _shaderFilePath{};
        std::string _shaderSource{};
        unsigned int _shaderId{};

        void errorCheck() const;
    };

} // Rendering
// Bibi

#endif //BIBI_SHADER_HPP
