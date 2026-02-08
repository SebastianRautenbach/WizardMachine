#include "core/camera3D.h"

wizmrenderer::camera3D::camera3D()
    : m_fov(45.0f)
{
    set_aspect_ratio(4.f/3.f);
}

void wizmrenderer::camera3D::save_data(std::string parent_name, std::string index, filedata::ZER& save_t) const
{
}

void wizmrenderer::camera3D::read_saved_data(std::string parent_name, std::string index, filedata::ZER& save_t)
{
}

const glm::mat4& wizmrenderer::camera3D::get_view_matrix()
{
    if(is_dirty())
        m_view_matrix = glm::lookAt(get_position(),get_position() + get_forward_vector(), get_up_vector() );
    
    clear_dirty_transform();
    return m_view_matrix;
}

const glm::mat4& wizmrenderer::camera3D::get_projection_matrix()
{
    m_projection_matrix = glm::perspective(get_fov(), get_aspect_ratio(), get_near(), get_far());
    return m_projection_matrix;
}
