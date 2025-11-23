#include "core_input.h"

wizmplatform::core_input::core_input(pwizm_window window, float width, float height)
	:m_window(window), w_width(width), w_height(height)
{
	last_mouse_pos.x = width / 2;
	last_mouse_pos.y = height / 2;

	glfwSetKeyCallback(window, core_input::keyCallback);
	glfwSetScrollCallback(window, core_input::scroll_callback);

	m_mouse_info.scroll_offset = 0.0f;
}

void wizmplatform::core_input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		keys[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		keys[key] = false;
	}
}

void wizmplatform::core_input::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	m_mouse_info.scroll_offset = static_cast<float>(yoffset);
}

bool wizmplatform::core_input::has_key_been_pressed(int key)
{
	auto it = keys.find(key);
	if (it != keys.end()) {
		return it->second;
	}
	return false;
}

void wizmplatform::core_input::set_mouse_offset(float x, float y)
{
	m_mouse_info.x_offset = x; m_mouse_info.y_offset = y;
}

void wizmplatform::core_input::set_mouse_cursor_pos(double mouse_x, double mouse_y)
{	
	glfwSetCursorPos(m_window, (w_width / 2), (w_height / 2));
}

void wizmplatform::core_input::set_hide_mouse_cursor(bool hide)
{
	hide ? glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN) : glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void wizmplatform::core_input::set_mouse_scroll_offset(float offset)
{
	m_mouse_info.scroll_offset = offset;
}

wizmplatform::mouse_info wizmplatform::core_input::get_mouse_offset_new()
{
	double mouse_x, mouse_y;
	mouse_info return_info;



	if (!m_mouse_info.mousemoved)
	{
		set_mouse_cursor_pos(w_width / 2, w_height / 2);
		glfwGetCursorPos(m_window, &mouse_x, &mouse_y);

		last_mouse_pos.x = mouse_x;
		last_mouse_pos.y = mouse_y;
		m_mouse_info.mousemoved = true;
	}
	else
	{

		glfwGetCursorPos(m_window, &mouse_x, &mouse_y);
	}


	return_info.x_offset = mouse_x - last_mouse_pos.x;
	return_info.y_offset = -last_mouse_pos.y + mouse_y;

	last_mouse_pos.x = mouse_x;
	last_mouse_pos.y = mouse_y;

	set_mouse_cursor_pos(w_width / 2, w_height / 2);

	return return_info;
}

void wizmplatform::core_input::mouse_stop_move()
{
	m_mouse_info.mousemoved = false;
}


std::unordered_map<int, bool> wizmplatform::core_input::keys;
wizmplatform::mouse_info wizmplatform::core_input::m_mouse_info;
wizmcore::math::vec2<double> wizmplatform::core_input::last_mouse_pos;
