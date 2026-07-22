#include "system/camera_3d.h"

#include <GLFW/glfw3.h>

#include "math/matrix_transforms.h"

namespace wizm
{
    namespace renderer
    {
        camera_3d::camera_3d(const camera_settings& settings, math::vec3<float> position, math::vec3<float> rotation,
            math::vec3<float> scale)
                :camera(settings)
        {
        }

        void camera_3d::update(float delta_time)
        {
            float speed = m_settings.speed * delta_time;
            
            for(char x : m_active_move_states){
                switch (x){
                case e_forward:
                    m_position += m_front * speed;
                    break;

                case e_backward:
                    m_position -= m_front * speed;
                    break;

                case e_left:
                    m_position -= m_right * speed;
                    break;

                case e_right:
                    m_position += m_right * speed;
                    break;

                case e_up:
                    m_position += m_up * speed;
                    break;

                case e_down:
                    m_position -= m_up * speed;
                    break;
                }
                m_active_move_states.erase(m_active_move_states.begin());
            }
        
            m_target = m_position + m_front;
            m_view_matrix = math::lookAt(m_position, m_target, m_up);
            m_projection_matrix = math::perspective(math::radians(m_settings.fov), m_settings.aspect, m_settings.near, m_settings.far);
        }

        void camera_3d::reset_camera()
        {
        }

        float camera_3d::get_pitch() const
        {
            return math::degrees(math::asin(m_front[1]));
        }

        float camera_3d::get_yaw() const
        {
            return math::degrees(math::acos(m_front[0] / math::cos(math::radians(m_rotation[1]))));
        }

        void camera_3d::update_orientation()
        {
            m_front[0] = math::cos(math::radians(m_rotation[1])) * math::cos(math::radians(m_rotation[0]));
            m_front[1] = math::sin(math::radians(m_rotation[1]));
            m_front[2] = math::cos(math::radians(m_rotation[1])) * math::sin(math::radians(m_rotation[0]));
            m_front = math::normalize(m_front);
            m_right = math::normalize(math::cross(m_front, m_up));
        }

        void camera_3d::add_movement(e_camera_move_direction movement)
        {
            m_active_move_states.insert(movement);
        }

        math::mat4<float> camera_3d::get_view_matrix() const
        {
            return m_view_matrix;
        }

        math::mat4<float> camera_3d::get_projection_matrix() const
        {
            return m_projection_matrix;
        }
    }
}
