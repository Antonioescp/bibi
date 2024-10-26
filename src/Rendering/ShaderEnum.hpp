//
// Created by packa on 26/10/2024.
//

#ifndef BIBI_SHADERENUM_HPP
#define BIBI_SHADERENUM_HPP

#include <glad/glad.h>
#include "Core/Enum.hpp"

namespace Bibi::Rendering {

    class ShaderEnum : public Core::Enum<int> {
    public:
        static const ShaderEnum& VERTEX_SHADER;
        static const ShaderEnum& FRAGMENT_SHADER;

    protected:
        using Core::Enum<int>::Enum;
    };

} // Rendering

#endif //BIBI_SHADERENUM_HPP
