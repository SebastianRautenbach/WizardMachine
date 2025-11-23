#include "wwindow.h"
#include "core_input.h"

wizmplatform::wwindow::wwindow(const char* name, double w, double h)
	:m_screen_width(w), m_screen_height(h)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(w, h, name, NULL, NULL);

	if (!m_window)
	{
		glfwTerminate();
		return;
	}


	//glfwSetWindowUserPointer(glfwWindow, this);
	//glfwSetWindowSizeCallback(glfwWindow, WindowResizeCallback);


	glfwMakeContextCurrent(m_window);
}

wizmplatform::wwindow::~wwindow()
{
	glfwTerminate();
}