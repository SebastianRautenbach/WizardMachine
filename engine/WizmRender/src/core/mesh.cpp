#include "core/mesh.h"

wizmrenderer::core_mesh::core_mesh(std::vector<vertex_data> vertices, std::vector<unsigned int> indices,
    int material_index)
    : vertices(std::move(vertices)), indices(std::move(indices)),  m_material_index(material_index)
{
        setup_mesh();
}

wizmrenderer::core_mesh::core_mesh(core_mesh&& other) noexcept
: vertices(std::move(other.vertices)),
        indices(std::move(other.indices)),        
        vertex_arr(std::move(other.vertex_arr)),
        m_material_index(other.m_material_index)
{
}

void wizmrenderer::core_mesh::draw_mesh()
{
    vertex_arr.draw_buffer(static_cast<unsigned int>(indices.size()));
}

wizmrenderer::core_mesh& wizmrenderer::core_mesh::operator=(core_mesh&& other) noexcept
{
    if (this != &other) {
        vertices = std::move(other.vertices);
        indices = std::move(other.indices);            
        vertex_arr = std::move(other.vertex_arr);
    }
    return *this;
}

void wizmrenderer::core_mesh::setup_mesh()
{
    vertex_arr = arr_vertex_buffer(vertices, indices);
    vertex_arr.bind_buffer();
    vertex_arr.create_attrib_arr(0, 3, sizeof(vertex_data), 0); // pos
    vertex_arr.create_attrib_arr(1, 3, sizeof(vertex_data), offsetof(vertex_data, Normal)); // normal
    vertex_arr.create_attrib_arr(2, 2, sizeof(vertex_data), offsetof(vertex_data, TexCoords)); // TextureUV
    vertex_arr.create_buffer();
}
