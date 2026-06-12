#include "../includes/glfw_platform_window.h"
#include  "../includes/platform_input.h"
#include <GLFW/glfw3.h>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

float wizm::platform::glfw_platform_window::get_time() const
{
   return static_cast<float>(glfwGetTime());
}

wizm::platform::glfw_platform_window::glfw_platform_window(wizm::platform::window_desc const& desc)
{
    m_desc = desc;
    
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    m_window = glfwCreateWindow(desc.m_width, desc.m_height, desc.m_title, NULL, NULL);
    
    glfwSetWindowUserPointer(m_window, this);
    
    if (!m_window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        glfw_platform_window& _window = *((glfw_platform_window*)glfwGetWindowUserPointer(window));
        
        switch (action)
            {
                case GLFW_PRESS:
        case GLFW_REPEAT:
                    {
                        key_pressed_event event(key, action == GLFW_REPEAT);
                        _window.raise_event(event);
                        break;
                    }
                    case GLFW_RELEASE:
                    {
                        key_released_event event(key);
                        _window.raise_event(event);
                        break;
                    }
                }
    });
    
    glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos)
    {
        glfw_platform_window& _window = *((glfw_platform_window*)glfwGetWindowUserPointer(window));
        
        mouse_move_event event(xpos, ypos);
        _window.raise_event(event);
    });
    
    
    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
}

wizm::platform::glfw_platform_window::~glfw_platform_window()
{
    glfwTerminate();
}

void wizm::platform::glfw_platform_window::raise_event(core::core_event& event) const
{
    if (m_desc.event_callback)
        m_desc.event_callback(event);
}

void wizm::platform::glfw_platform_window::poll_events()
{
    glfwPollEvents();
}

void wizm::platform::glfw_platform_window::swap_buffers()
{
    glfwSwapBuffers(m_window);
}

bool wizm::platform::glfw_platform_window::should_close() const
{
   return glfwWindowShouldClose(m_window);
}

uint32_t wizm::platform::glfw_platform_window::get_width() const
{
    int width, height;
    glfwGetWindowSize(m_window, &width, &height);
    return static_cast<uint32_t>(width);
}

uint32_t wizm::platform::glfw_platform_window::get_height() const
{
    int width, height;
    glfwGetWindowSize(m_window, &width, &height);
    return static_cast<uint32_t>(height);
}

void* wizm::platform::glfw_platform_window::get_native_window() const
{
    return m_window;
}
