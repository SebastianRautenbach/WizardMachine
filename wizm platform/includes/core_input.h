#pragma once
#include <GLFW/glfw3.h>
#include "system/updateable.h"
#include "definitions/core_definitions.h"
#include "math/vec2.h"
#include <unordered_map>

namespace wizmplatform {


	struct mouse_info {
		double x_offset, y_offset;
		bool mousemoved;
		float scroll_offset;
	};

	class core_input {

	public:
		
		core_input(pwizm_window window, float width, float height);

		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

		bool has_key_been_pressed(int key);


		void set_mouse_offset(float x, float y); 
		void set_mouse_cursor_pos(double mouse_x, double mouse_y);
		void set_hide_mouse_cursor(bool hide); 
		void set_mouse_scroll_offset(float offset = 0); 


		mouse_info get_mouse_offset_new();
		mouse_info get_mouse_offset() { return m_mouse_info; }
		void get_mouse_pos(double& mouse_x, double& mouse_y) { glfwGetCursorPos(m_window, &mouse_x, &mouse_y); }
		float get_mouse_scroll_offset() { return m_mouse_info.scroll_offset; }

		void mouse_stop_move();


	private:
		float w_width, w_height;
		static wizmcore::math::vec2<double> last_mouse_pos;
		static mouse_info m_mouse_info;
		static std::unordered_map<int, bool> keys;
		pwizm_window m_window = nullptr;
	};
}
