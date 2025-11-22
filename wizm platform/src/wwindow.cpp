#include "wwindow.h"
#include "core_input.h"

void wizmplatform::wwindow::pre_update(float delta_time)
{
}

void wizmplatform::wwindow::update(float delta_time)
{
	if (m_input->has_key_been_pressed(GLFW_KEY_LEFT_ALT)) {

	}
}

void wizmplatform::wwindow::post_update(float delta_time)
{
	glfwPollEvents();
	glfwSwapBuffers(m_window);
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


	glfwMakeContextCurrent(m_window);


	m_input = std::make_shared<core_input>(m_window, m_screen_width, m_screen_height);;
}

wizmplatform::wwindow::~wwindow()
{
	glfwTerminate();
}

void wizmplatform::wwindow::set_window_size(double w, double h)
{

}
