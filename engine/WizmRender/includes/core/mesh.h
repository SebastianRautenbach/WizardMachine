#pragma once
#include "math/pch_math.h"
#include <vector>
#include <string>
#include <core/gl/core_shader.h>
#include "core/gl/vertex_buffer.h"

namespace wizmrenderer
{
    class core_mesh
    {
    public:
        core_mesh(std::vector<vertex_data> vertices, std::vector<unsigned int> indices, int material_index);
        core_mesh(core_mesh&& other) noexcept;
		
        void draw_mesh();
        ~core_mesh() = default;


        core_mesh& operator=(core_mesh&& other) noexcept;

	
    public:
        std::vector<vertex_data> vertices;
        std::vector<unsigned int> indices;		
        int m_material_index;

    private:
        arr_vertex_buffer vertex_arr;
        void setup_mesh();
    };    
}

