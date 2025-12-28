#pragma once
#include "render/renderlisttypes.h"
#include "math/vec_types.h"

namespace wizmrenderer
{
    class mesh;
    class material;
    class camera3D;
    
    class renderlist
    {
    public:
        void add_to_render(mesh const& pmesh, material const& pmaterial, wizmcore::math::mat4 ptransformation, camera3D const& pcamera);
    };    
}


