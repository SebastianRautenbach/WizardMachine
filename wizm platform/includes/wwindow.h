#pragma once
#include <GLFW/glfw3.h>
#include "definitions/core_definitions.h"
#include <memory>
#include "window_context.h"


namespace wizmplatform   {
		
	class wwindow : public window_context {
	public:

		int GetWidth() const override { int w, h; glfwGetWindowSize(m_window, &w, &h); return w; };
		int GetHeight() const override { int w, h; glfwGetWindowSize(m_window, &w, &h); return h; };
		bool ShouldClose() const override { return glfwWindowShouldClose(m_window); };
		void* GetNativeHandle() override { return (void*)m_window; };
		
		
		wwindow(const char* name, double w, double h);	
		~wwindow();
				

	private:
		pwizm_window m_window;		
		double m_screen_width =900., m_screen_height=900.;
	};
}
