//
// Created by packa on 25/10/2024.
//

#ifndef BIBI_MESH_HPP
#define BIBI_MESH_HPP

#include <array>

namespace Bibi::Rendering {

    class Mesh {
    public:
        std::array<float, 9> vertices{
            -0.5f, -0.5f, 0.0f, // bottom left
            0.5f, -0.5f, 0.0f, // bottom right
            0.0f, 0.5f, 0.0f // top
        };
    };

} // Rendering

#endif //BIBI_MESH_HPP
