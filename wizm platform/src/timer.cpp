#include "timer.h"
#include <GLFW/glfw3.h>


namespace wizmplatform {
	void core_timer::update_delta_time()
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
	}
	
	float core_timer::get_delta_time()
	{
		return deltaTime;
	}
}