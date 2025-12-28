#include "core/camera3D.h"

wizmrenderer::camera3D::camera3D(int window_width, int window_height, float fov, float near_plane, float far_plane,
    float speed)
    :m_window_width(window_width) ,m_window_height(window_height), m_fov(fov), m_near_plane(near_plane),
m_far_plane(far_plane), m_speed(speed)
{
    m_rotation_matrix = math::mat4(1.f);
}

void wizmrenderer::camera3D::update_projection_matrix()
{
}

void wizmrenderer::camera3D::update_rotation_matrix()
{
}

void wizmrenderer::camera3D::set_fov(float fov)
{
}

void wizmrenderer::camera3D::set_aspect_ratio(float aspect_ratio)
{
}

void wizmrenderer::camera3D::set_window_size(int window_width, int window_height)
{
}

void wizmrenderer::camera3D::set_aspect_ratio(int aspect_ratio)
{
}

void wizmrenderer::camera3D::set_position(const math::vec3& position)
{
}

void wizmrenderer::camera3D::set_rotation(const math::quat& rotation)
{
}

void wizmrenderer::camera3D::set_rotation(const math::vec3& rotation)
{
}

void wizmrenderer::camera3D::set_rotation_matrix(const math::mat4& rotation_matrix)
{
}

void wizmrenderer::camera3D::add_yaw(float yaw)
{
}

void wizmrenderer::camera3D::add_pitch(float pitch)
{
}

void wizmrenderer::camera3D::add_roll(float roll)
{
}

void wizmrenderer::camera3D::move_up(float distance)
{
}

void wizmrenderer::camera3D::move_right(float distance)
{
}

void wizmrenderer::camera3D::move_forward(float distance)
{
}

void wizmrenderer::camera3D::set_speed(float speed)
{
}

void wizmrenderer::camera3D::add_speed(float speed)
{
}

void wizmrenderer::camera3D::update_aspect_ratio()
{
}

wizmrenderer::camera3D::~camera3D()
{
}

void wizmrenderer::camera3D::update_view_matrix()
{
}

wizmrenderer::e_camera_type wizmrenderer::camera3D::get_camera_type()
{
    return eCameraType_3D;
}
