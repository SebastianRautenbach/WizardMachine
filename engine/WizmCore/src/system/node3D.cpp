#include "system/node3D.h"

void wizmcore::node3D::set_position(const glm::vec3& position)
{
    m_translation = position;
    make_transform_dirty();
}

void wizmcore::node3D::add_position(const glm::vec3& offset)
{
    m_translation += offset;
    make_transform_dirty();
}

void wizmcore::node3D::set_rotation(const glm::vec3& rotation)
{
    m_rotation = rotation;
    make_transform_dirty();
}

void wizmcore::node3D::add_rotation(const glm::vec3& deltaRotation)
{
    m_rotation += deltaRotation;
    make_transform_dirty();
}

void wizmcore::node3D::set_scale(const glm::vec3& scale)
{
    m_scale = scale;
    make_transform_dirty();
}

void wizmcore::node3D::add_scale(const glm::vec3& deltaScale)
{
    m_scale += deltaScale;
    make_transform_dirty();
}

void wizmcore::node3D::move_forward(const float distance)
{
    m_translation += get_forward_vector() * distance;
    make_transform_dirty();
}

void wizmcore::node3D::move_right(const float distance)
{
    m_translation += get_right_vector() * distance;
    make_transform_dirty();
}

void wizmcore::node3D::move_up(const float distance)
{    
    m_translation += get_up_vector() * distance;
    make_transform_dirty();
}
