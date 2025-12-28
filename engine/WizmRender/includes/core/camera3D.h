#pragma once
#include "core_camera.h"
#include "math/quat.h"
#include "math/vec_types.h"
#include "math/mat4x4.h"
#include "system/node.h"

using namespace wizmcore;

namespace wizmrenderer {
	class camera3D : public core_camera {

	public:
		~camera3D();
		
		camera3D (
		int window_width, 
		int window_height,
		float fov = 60.f,
		float near_plane = 0.1f,
		float far_plane = 1000.f,
		float speed = 0.01f
		);
		
		void update_aspect_ratio();
		void update_projection_matrix();
		void update_rotation_matrix();
		
		void set_fov(float fov);
		void set_aspect_ratio(float aspect_ratio);
		
		void set_window_size(int window_width, int window_height);
		void set_aspect_ratio(int aspect_ratio);
		
		//--------------------------------------------- TRANSFORMATION
		
		void set_position(const math::vec3& position);
		void set_rotation(const math::quat& rotation);
		void set_rotation(const math::vec3& rotation);
		void set_rotation_matrix(const math::mat4& rotation_matrix);
		
		void add_yaw(float yaw);
		void add_pitch(float pitch);
		void add_roll(float roll);
		
		void move_up(float distance);
		void move_right(float distance);
		void move_forward(float distance);
		
		void set_speed(float speed);
		void add_speed(float speed);
		
		
	public:
		void update_view_matrix() override;
		e_camera_type get_camera_type() override;

	private:
		int m_window_width, m_window_height;
		e_camera_type m_type;
		
		float m_fov;
		float m_aspect_ratio;
		float m_near_plane;
		float m_far_plane;
		float m_speed;
		
		math::vec3 m_position;
		
		math::mat4 m_view_matrix = math::mat4(0.f);
		math::mat4 m_projection_matrix = math::mat4(0.f);
		math::mat4 m_rotation_matrix = math::mat4(1.f);
	};
}