#pragma once
#include "core_camera.h"
#include "math/vec_types.h"
#include "math/vec4.h"
#include "math/vec3.h"
#include "math/mat4x4.h"

using namespace wizmcore;

namespace wizmrenderer {
	class camera3D : public core_camera {
	
	public:
		camera3D();
		~camera3D() = default;
		
	public:
		void set_model_view_matrix() override;
		void set_projection_matrix() override;
		e_camera_type get_camera_type() override;
	
	public:
		math::vec3 get_forward();
		math::vec3 get_right();
		math::vec3 get_up();
		
	private:
	
		float m_pitch;
		float m_yaw;
		float m_roll;
		
		float m_near_plane;
		float m_far_plane;
		
		math::vec3 m_position;
		
		math::mat4 m_view_matrix, m_prev_view_matrix;
		math::mat4 m_projection_matrix, m_prev_projection_matrix;
		
		float m_sensitivity = 0.001;
		float mSpeed = 5.0f;
	};
}