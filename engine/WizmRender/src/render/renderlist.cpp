#include "render/renderlist.h"

#include <algorithm>

#include "core/camera3D.h"
#include "core/material.h"
#include "core/mesh.h"

void wizmrenderer::renderlist::add_to_render(mesh* _mesh, material* _material, glm::mat4 const& _transformation)
{
    render_item item;
    
    item.mesh = _mesh;
    item.material = _material;
    item.transformation = _transformation;
    
    glm::vec3 world_pos = glm::vec3(_transformation[3]);
    glm::vec4 view_pos = m_camera->get_view_matrix() * glm::vec4(world_pos, 1.0f);
    float depth = -view_pos.z;
    uint32_t depth_bits;
    memcpy(&depth_bits, &depth, sizeof(float));

    item.sort_key = depth_bits;
    
    m_opaque_render_items.push_back(item);
}

void wizmrenderer::renderlist::render_items() const
{
}

void wizmrenderer::renderlist::set_camera(camera3D* camera)
{
    m_camera = camera;
}

void wizmrenderer::renderlist::order_lists()
{
    std::sort(m_opaque_render_items.begin(), m_opaque_render_items.end(), sort_key_comparator_ftb);
    std::sort(m_transparent_render_items.begin(), m_transparent_render_items.end(), sort_key_comparator_btf);
}

// forth to back
bool wizmrenderer::renderlist::sort_key_comparator_ftb(render_item const& a, render_item const& b)
{
    return a.sort_key > b.sort_key;
}

// back to forth
bool wizmrenderer::renderlist::sort_key_comparator_btf(render_item const& a, render_item const& b)
{
    return a.sort_key < b.sort_key;
}
