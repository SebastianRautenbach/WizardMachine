#include "timer.h"
#include <iostream>
#include <GLFW/glfw3.h>

int main() {

	wizmplatform::core_timer t;

	GLFWwindow* window;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(900, 900, "test", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return 0;
	}


	glfwMakeContextCurrent(window);





}