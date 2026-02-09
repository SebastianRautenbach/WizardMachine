#pragma once
#include "math/pch_math.h"
#include "system/node3D.h"

namespace wizmrenderer {


	enum e_camera_type {
		eCameraType_Perspective,
		eCameraType_Orthographic,
	};



	class core_camera : public wizmcore::node3D {
		
	public:
		virtual e_camera_type get_camera_type() = 0;
		
	public:
		float get_aspect_ratio() const { return m_aspect; }
		float get_near() const { return m_near; }
		float get_far() const { return m_far; }
		unsigned int get_screen_width() const { return m_screen_width; }
		unsigned int get_screen_height() const{ return m_screen_height; }
	
		void set_aspect_ratio(float aspect_ratio) { m_aspect = aspect_ratio; }
		void set_near(float near) { m_near = near; }
		void set_far(float far) { m_far = far; }
		void set_screen_width(unsigned int width) { m_screen_width = width; }
		void set_screen_height(unsigned int height) { m_screen_height = height; }
		
	private:
		float m_aspect;
		float m_near = 0.1f;
		float m_far = 100.0f;
		unsigned int m_screen_width = 1280;
		unsigned int m_screen_height = 720;		
	};
}
