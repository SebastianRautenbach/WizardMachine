#include "wplatform.h"

namespace wizmplatform {
	wplatform::wplatform(wizmplatform::wwindow window)
		: m_window(window)
	{
	}
	wplatform::~wplatform()
	{
	}
	void wplatform::pre_update(float delta_time)
	{
		glfwPollEvents();
	}
	void wplatform::update(float delta_time)
	{
	}
	void wplatform::post_update(float delta_time)
	{
	}
}
