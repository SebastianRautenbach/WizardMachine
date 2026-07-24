#include "system/node_3d.h"

wizm::core::node_3d::node_3d()
    : m_position(0.0f), m_rotation(0.0f), m_scale(1.0f)
{
}

void wizm::core::node_3d::set_position(const math::vec3<float>& position)
{
    m_position = position;
}

void wizm::core::node_3d::set_rotation(const math::vec3<float>& rotation)
{
    m_rotation = rotation;
}

void wizm::core::node_3d::set_scale(const math::vec3<float>& scale)
{
    m_scale = scale;
}

void wizm::core::node_3d::add_position(const math::vec3<float>& position)
{
    m_position += position;
}

void wizm::core::node_3d::add_rotation(const math::vec3<float>& rotation)
{
    m_rotation += rotation;
}

void wizm::core::node_3d::add_scale(const math::vec3<float>& scale)
{
    m_scale += scale;
}
