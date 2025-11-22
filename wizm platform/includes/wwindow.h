#pragma once
#include <GLFW/glfw3.h>
#include "system/updateable.h"
#include "definitions/core_definitions.h"
#include <memory>


namespace wizmplatform  {
	
	class core_input;
	
	class wwindow : public wizmcore::system::updateable {
	public:					
		void pre_update(float delta_time) override;
		void update(float delta_time) override;
		void post_update(float delta_time) override;
		
		
		
		
		wwindow(const char* name, double w, double h);	
		~wwindow();
		
		
		
		
		pwizm_window get_window() { return m_window; }
		double get_screen_width() { return m_screen_width; }
		double get_screen_height() { return m_screen_height; }


		void set_window_size(double w, double h);

	private:
		pwizm_window m_window;
		std::shared_ptr<core_input> m_input;
		double m_screen_width =900., m_screen_height=900.;
	};
}
