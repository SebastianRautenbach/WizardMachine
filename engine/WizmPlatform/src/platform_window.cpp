#include "../includes/platform_window.h"
#include "../includes/glfw_platform_window.h"
#include "../includes/platform_input.h"

wizm::platform::platform_window* wizm::platform::create_window(window_desc const& desc)
{
    return new wizm::platform::glfw_platform_window(desc);
}