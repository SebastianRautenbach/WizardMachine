#pragma once
#include <memory>
#include "render/renderlisttypes.h"
#include "math/pch_math.h"
#include "system/node.h"
#include "engine types/handle.h"

namespace wizmrenderer
{
    class mesh;
    class material;
    class camera3D;
    
    class render_node : wizmcore::core_node
    {
    public:
        wizmcore::Handle m_mesh_handle;
        wizmcore::Handle m_material_handle;
        uint32_t submesh_index;
        glm::mat4 world_transform;
        uint64_t sort_key;
    };
    
    class renderlist
    {
    public:
        void add_to_render(mesh const& pmesh, material const& pmaterial, glm::mat4& ptransformation, camera3D const& pcamera);
        
        std::vector<render_node> m_render_items;
    };    
}


