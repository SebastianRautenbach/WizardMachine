#pragma once
#include <GLFW/glfw3.h>


typedef GLFWwindow* wizm_window;


namespace wizmplatform {
	class wwindow {
	public:
		
		wwindow();
		
		wizm_window get_window() { return m_window; }

	private:
		wizm_window m_window;
	};
}
