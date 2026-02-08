#pragma once
#include "math/pch_math.h"
#include "core_buffer.h"
#include <vector>

namespace wizmrenderer {


	struct attrib_info {
		unsigned int layout;
		int size;
		int stride;
		int attrib_length;

		attrib_info(unsigned int v1,
			int v2,
			int v3,
			int v4
		) : layout(v1), size(v2), stride(v3), attrib_length(v4)
		{}
	};


	struct vertex_data {
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 TexCoords;
		glm::vec3 Tangent;
		glm::vec3 Bitangent;
		int m_BoneIDs[4];
		float m_Weights[4];
	};


	class vertex_buffer : public core_buffer_object {
	public:
		void gen_buffer() override;
		void bind_buffer() override;
		void unbind_buffer() override;
		void destroy_buffer() override;

		// default constructor 
		vertex_buffer(std::vector<vertex_data>& vertices) : mvertices(vertices) { gen_buffer(); }

	public:
		std::vector<vertex_data> mvertices;
	};


	class index_buffer : public core_buffer_object {
	public:
		void gen_buffer() override;
		void bind_buffer() override;
		void unbind_buffer() override;
		void destroy_buffer() override;

		// default constructor 
		index_buffer(std::vector<unsigned int>& indices) : mindices(indices) { gen_buffer(); }

	public:
		std::vector<unsigned int> mindices;
	};

	class arr_vertex_buffer : public core_buffer_object {

	public:
		// default constructor
		arr_vertex_buffer(std::vector<vertex_data>& vertices, std::vector<unsigned int>& indices);
		arr_vertex_buffer() {}
		~arr_vertex_buffer();

		void create_buffer();
		void draw_buffer(unsigned int size_of_row);
		void bind_buffer() override;
		void unbind_buffer() override;
		void destroy_buffer() override;
		void create_attrib_arr(unsigned int layout, int size, int stride, int attrib_length);

	public:
		index_buffer* ibo = nullptr;
		vertex_buffer* vbo = nullptr;
		std::vector<attrib_info> vertex_attribs;

	};

}