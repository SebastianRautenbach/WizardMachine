#include "core/gl/vertex_buffer.h"
#include "glad.h"



//////////////////////////////////////////////////////////////////////////
// VERTEX BUFFER
//////////////////////////////////////////////////////////////////////////


void wizmrenderer::vertex_buffer::gen_buffer()
{
	glGenBuffers(1, &this->buffer_id); 
}

void wizmrenderer::vertex_buffer::bind_buffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, this->buffer_id);
	glBufferData(GL_ARRAY_BUFFER, this->mvertices.size() * sizeof(vertex_data), &this->mvertices[0], GL_STATIC_DRAW);
}

void wizmrenderer::vertex_buffer::unbind_buffer()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void wizmrenderer::vertex_buffer::destroy_buffer()
{
	glDeleteBuffers(1, &this->buffer_id);
}


//////////////////////////////////////////////////////////////////////////
// INDEX BUFFER
//////////////////////////////////////////////////////////////////////////




void wizmrenderer::index_buffer::gen_buffer()
{
	glGenBuffers(1, &this->buffer_id);
}

void wizmrenderer::index_buffer::bind_buffer()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->buffer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->mindices.size() * sizeof(unsigned int), this->mindices.data(), GL_STATIC_DRAW);
}

void wizmrenderer::index_buffer::unbind_buffer()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void wizmrenderer::index_buffer::destroy_buffer()
{
	glDeleteBuffers(1, &this->buffer_id);
}

//////////////////////////////////////////////////////////////////////////
// ARRAY BUFFER
//////////////////////////////////////////////////////////////////////////


wizmrenderer::arr_vertex_buffer::arr_vertex_buffer(std::vector<vertex_data>& vertices, std::vector<unsigned int>& indices)
{
	glGenVertexArrays(1, &this->buffer_id);
	vbo = new vertex_buffer(vertices);
	ibo = new index_buffer(indices);
}

wizmrenderer::arr_vertex_buffer::~arr_vertex_buffer()
{
}

void wizmrenderer::arr_vertex_buffer::create_buffer()
{
	bind_buffer();

	vbo->bind_buffer();
	ibo->bind_buffer();

	for (const auto& i : vertex_attribs)
	{
		glVertexAttribPointer(i.layout, i.size, GL_FLOAT, GL_FALSE, i.stride, (void*)(intptr_t)i.attrib_length);
		glEnableVertexAttribArray(i.layout);
	}

	vbo->unbind_buffer();
	unbind_buffer();
}

void wizmrenderer::arr_vertex_buffer::draw_buffer(unsigned int size_of_row)
{
	bind_buffer();
	glDrawElements(GL_TRIANGLES, size_of_row, GL_UNSIGNED_INT, 0);
}

void wizmrenderer::arr_vertex_buffer::bind_buffer()
{
	glBindVertexArray(this->buffer_id);
}

void wizmrenderer::arr_vertex_buffer::unbind_buffer()
{
	glBindVertexArray(0);
}

void wizmrenderer::arr_vertex_buffer::destroy_buffer()
{
	vbo->destroy_buffer();
	ibo->destroy_buffer();
	glDeleteBuffers(1, &this->buffer_id);
}

void wizmrenderer::arr_vertex_buffer::create_attrib_arr(unsigned int layout, int size, int stride, int attrib_length)
{
	attrib_info m = attrib_info(layout, size, stride, attrib_length);
	vertex_attribs.emplace_back(layout, size, stride, attrib_length);
}
