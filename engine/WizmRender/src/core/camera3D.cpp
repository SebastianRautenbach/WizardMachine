#include "core/camera3D.h"
#include "math/generic_mat_func.h"
#include "math/generic_vec_func.h"

void wizmrenderer::camera3D::set_model_view_matrix()
{
}

void wizmrenderer::camera3D::set_projection_matrix()
{
}

wizmrenderer::camera3D::camera3D(float fov, float near_plane, float far_plane,
                                 float speed)
    : m_fov(fov), m_near_plane(near_plane),
m_far_plane(far_plane), m_speed(speed)
{
}

void wizmrenderer::camera3D::set_fov(float fov)
{
    m_fov = fov;
    m_has_projection_updated = true;
}

void wizmrenderer::camera3D::set_aspect_ratio(float aspect_ratio)
{
    m_aspect_ratio = aspect_ratio;
    m_has_projection_updated = true;
}

void wizmrenderer::camera3D::set_far_plane(float far_plane)
{
    m_far_plane = far_plane;
    m_has_projection_updated = true;
}

void wizmrenderer::camera3D::set_near_plane(float near_plane)
{
    m_near_plane = near_plane;
    m_has_projection_updated = true;
}

void wizmrenderer::camera3D::reset_rotation()
{
    
    //
    m_has_view_updated = true;
}

void wizmrenderer::camera3D::set_position(const math::vec3& position)
{
    m_position = position;
    m_has_view_updated = true;
}

void wizmrenderer::camera3D::set_yaw(float yaw)
{
}

void wizmrenderer::camera3D::set_pitch(float pitch)
{
}

void wizmrenderer::camera3D::set_roll(float roll)
{
}


const math::mat4& wizmrenderer::camera3D::get_view_matrix()
{
    if (m_has_view_updated)
    {
        math::vec3 forward = get_forward_vector();
        math::vec3 up = get_up_vector();
        m_view_matrix = math::lookAt(m_position, m_position + forward, up);
        m_has_projection_updated = false;
        return m_view_matrix; 
    } 
    return m_view_matrix;
}

const math::mat4& wizmrenderer::camera3D::get_projection_matrix()
{
    if (m_has_projection_updated)
    {
        m_projection_matrix = math::perspective(m_fov, m_aspect_ratio, m_near_plane, m_far_plane);
        m_has_projection_updated = false;
        return m_projection_matrix;
    }
    return m_projection_matrix;
}

const math::mat4& wizmrenderer::camera3D::get_rotation_matrix() const
{
    return m_rotation_matrix;
}

math::vec3 wizmrenderer::camera3D::get_forward_vector() const
{
    math::vec3 rot_m = math::vec3(m_rotation_matrix[2].x, m_rotation_matrix[2].y, m_rotation_matrix[2].z);
    return -math::normalize(rot_m);
}

math::vec3 wizmrenderer::camera3D::get_right_vector() const
{
    math::vec3 rot_m = math::vec3(m_rotation_matrix[0].x, m_rotation_matrix[0].y, m_rotation_matrix[0].z);
    return -math::normalize(rot_m);
}

math::vec3 wizmrenderer::camera3D::get_up_vector() const
{
    math::vec3 rot_m = math::vec3(m_rotation_matrix[1].x, m_rotation_matrix[1].y, m_rotation_matrix[1].z);
    return -math::normalize(rot_m);
}

wizmrenderer::e_camera_type wizmrenderer::camera3D::get_camera_type()
{
    return eCameraType_3D;
}
