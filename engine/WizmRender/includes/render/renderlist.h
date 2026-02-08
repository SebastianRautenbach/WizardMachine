#pragma once
#include "render/renderlisttypes.h"
#include "math/pch_math.h"

namespace wizmrenderer
{
    class mesh;
    class material;
    class camera3D;
    
    class renderlist
    {
    public:
        void add_to_render(mesh const& pmesh, material const& pmaterial, glm::mat4& ptransformation, camera3D const& pcamera);
    };    
}


