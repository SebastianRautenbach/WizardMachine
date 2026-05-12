#pragma once
#include <memory>
#include "render/renderlisttypes.h"
#include "math/pch_math.h"
#include "system/node.h"

namespace wizmrenderer
{
    class mesh;
    class material;
    class camera3D;
    class renderable;
    
    struct render_item
    {
        mesh* mesh;
        material* material;
        glm::mat4 transformation;
        uint64_t sort_key;
    };
    
    class renderlist
    {
    public:
        void add_to_render(mesh* _mesh, material* _material, glm::mat4 const& _transformation);
        void render_items() const;
        void set_camera(camera3D* camera);
        void order_lists();
        
    private:
        static bool sort_key_comparator_btf(render_item const& a, render_item const& b);
        static bool sort_key_comparator_ftb(render_item const& a, render_item const& b);
        
    private:
        std::vector<render_item> m_opaque_render_items;
        std::vector<render_item> m_transparent_render_items;
        camera3D* m_camera;
    };    
}


