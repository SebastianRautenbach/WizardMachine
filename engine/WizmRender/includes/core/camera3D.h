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

		void set_model_view_matrix() override;
		void set_projection_matrix() override;


		camera3D (
		float fov = 60.f,
		float near_plane = 0.1f,
		float far_plane = 1000.f,
		float speed = 0.01f
		);
		
		~camera3D() = default;
		
		void set_fov(float fov);
		void set_aspect_ratio(float aspect_ratio);
		
		void set_far_plane(float far_plane);
		void set_near_plane(float near_plane);
		
		void reset_rotation();
		
		//--------------------------------------------- TRANSFORMATION
		
		void set_position(const math::vec3& position);
		void set_rotation(const math::vec3& rotation);
		void set_rotation_matrix(const math::mat4& rotation_matrix);
		
		const math::vec3& get_position() const;
		
		void add_yaw(float yaw);
		void add_pitch(float pitch);
		void add_roll(float roll);
		
		void set_yaw(float yaw);
		void set_pitch(float pitch);
		void set_roll(float roll);
		
		void move_up(float distance);
		void move_right(float distance);
		void move_forward(float distance);
		
		void set_speed(float speed);
		void add_speed(float speed);
		
		
		const math::mat4& get_view_matrix();
		const math::mat4& get_projection_matrix();
		const math::mat4& get_rotation_matrix() const;
		
		math::vec3 get_forward_vector() const;
		math::vec3 get_right_vector() const;
		math::vec3 get_up_vector() const;
		
	public:
		e_camera_type get_camera_type() override;

	private:
		e_camera_type m_type;
		
		float m_fov;
		float m_aspect_ratio;
		float m_near_plane;
		float m_far_plane;
		float m_speed;
		
		math::vec3 m_position;
		
		math::mat4 m_projection_matrix;
		math::mat4 m_view_matrix;
		math::mat4 m_rotation_matrix = math::mat4(1.f);
		
		bool m_has_view_updated;
		bool m_has_projection_updated;

	};
}