#pragma once
#include "core_camera.h"
#include "math/pch_math.h"

using namespace wizmcore;

namespace wizmrenderer {
	class camera3D : public core_camera {
	
	public:
		camera3D();
		~camera3D() = default;
		
	public:
		void save_data(std::string parent_name, std::string index, filedata::ZER& save_t) const override;
		void read_saved_data(std::string parent_name, std::string index, filedata::ZER& save_t) override;
		e_camera_type get_camera_type() override { return eCameraType_Perspective; }
		
	public:
		const glm::mat4& get_view_matrix();
		const glm::mat4& get_projection_matrix();
		float get_fov() const { return m_fov; }
		const glm::vec2& get_pitch_limits() { return m_pitch_limits; }
		const glm::vec2& get_yaw_limits() { return m_yaw_limits; }
		
		void set_fov(float fov) { m_fov = fov; }
		void set_view_matrix(const glm::mat4& view_matrix) { m_view_matrix = view_matrix; }
		void set_projection_matrix (const glm::mat4& projection_matrix) { m_projection_matrix = projection_matrix; }
		void set_pitch_limits(const glm::vec2 limits) { m_pitch_limits = limits; }
		void set_yaw_limits(const glm::vec2 limits) { m_yaw_limits = limits; }
		
	private:
		glm::mat4 m_view_matrix;
		glm::mat4 m_projection_matrix;
		
		float m_fov;
		glm::vec2 m_pitch_limits;
		glm::vec2 m_yaw_limits;
	};
}