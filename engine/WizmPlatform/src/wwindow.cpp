#include "wwindow.h"
#include "core_input.h"
#include <glfw3.h>
#include "definitions/core_definitions.h"



int wizmplatform::wwindow::GetWidth() const
{
	int w, h; glfwGetWindowSize((pwizm_window)m_window, &w, &h); return w;
}

int wizmplatform::wwindow::GetHeight() const
{
	int w, h; glfwGetWindowSize((pwizm_window)m_window, &w, &h); return h;
}

bool wizmplatform::wwindow::ShouldClose() const
{
	return glfwWindowShouldClose((pwizm_window)m_window);
}

void* wizmplatform::wwindow::GetNativeHandle()
{
	return (void*)m_window;
}

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


	glfwMakeContextCurrent((pwizm_window)m_window);
}

wizmplatform::wwindow::~wwindow()
{
	glfwTerminate();
}