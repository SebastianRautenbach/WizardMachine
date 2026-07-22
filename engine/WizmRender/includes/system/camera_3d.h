#pragma once
#include <set>

#include "camera.h"
#include "math/math_pch.h"
#include "system/node_3d.h"

namespace wizm
{
    namespace renderer
    {
        enum e_camera_move_direction : uint32_t
        {
            e_forward = 0,
            e_backward,
            e_left,
            e_right,
            e_up,
            e_down,
        };
        
        class camera_3d : public camera, public core::node_3d
        {
        public:
            explicit camera_3d(
                const camera_settings& settings,
                math::vec3<float> position = math::vec3<float>(0.0f),
                math::vec3<float> rotation = math::vec3<float>(0.0f),
                math::vec3<float> scale = math::vec3<float>(1.0f)
                );

            void update(float delta_time) override;
            
            e_camera_type get_type() const override
            {
                return e_camera_type_3D;
            };
            
            // -----------------------------------------------------------------------------------
            
            void reset_camera();
            float get_pitch() const;
            float get_yaw() const;
            
            void update_orientation();
            void add_movement(e_camera_move_direction movement);
            
            math::mat4<float> get_view_matrix() const;
            math::mat4<float> get_projection_matrix() const;
            
        private:
            std::set<e_camera_move_direction> m_active_move_states;
            math::vec3<float> m_target = math::vec3<float>(0.0f);
            math::mat4<float> m_view_matrix = math::mat4<float>::identity();
            math::mat4<float> m_projection_matrix = math::mat4<float>::identity();
        };
    }
}
