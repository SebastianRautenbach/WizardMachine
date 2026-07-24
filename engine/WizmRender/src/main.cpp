#include <glad/glad.h>
#include "platform_window.h"
#include "platform_input.h"
#include <iostream>
#include <ranges>
#include <GLFW/glfw3.h>

#include "system/vertex_buffer.h"
#include "shader/shader.h"
#include "system/camera_3d.h"

#include "platform_input.h"

#include "math/matrix_transforms.h"

std::unique_ptr<wizm::renderer::camera_3d> cam;
float deltaTime = 0.0f;
float lastFrame = 0.0f;

double lastMouseX = 0.0;
double lastMouseY = 0.0;
bool firstMouse = true;

bool key_to_direction(int key_code, wizm::renderer::e_camera_move_direction& out)
{
    switch (key_code)
    {
    case GLFW_KEY_W: out = wizm::renderer::e_forward;  return true;
    case GLFW_KEY_S: out = wizm::renderer::e_backward; return true;
    case GLFW_KEY_D: out = wizm::renderer::e_right;    return true;
    case GLFW_KEY_A: out = wizm::renderer::e_left;     return true;
    case GLFW_KEY_E: out = wizm::renderer::e_up;       return true;
    case GLFW_KEY_Q: out = wizm::renderer::e_down;     return true;
    default: return false;
    }
}

void raise_event(wizm::core::core_event& event)
{
    if (!cam)
        return;

    wizm::renderer::e_camera_move_direction direction;

    if (event.get_event_type() == wizm::core::event_type::key_press)
    {
        auto& key_evt = dynamic_cast<wizm::platform::key_event&>(event);

        if (key_to_direction(key_evt.get_key_code(), direction))
            cam->add_movement(direction);
    }
    else if (event.get_event_type() == wizm::core::event_type::key_release)
    {
        auto& key_evt = dynamic_cast<wizm::platform::key_event&>(event);

        if (key_to_direction(key_evt.get_key_code(), direction))
            cam->remove_movement(direction);
    }
    else if (event.get_event_type() == wizm::core::event_type::mouse_move)
    {
        auto& mouse_event = dynamic_cast<wizm::platform::mouse_move_event&>(event);

        double mouse_x = mouse_event.get_x();
        double mouse_y = mouse_event.get_y();

        if (firstMouse)
        {
            lastMouseX = mouse_x;
            lastMouseY = mouse_y;
            firstMouse = false;
        }

        float x_offset = static_cast<float>(mouse_x - lastMouseX);
        float y_offset = static_cast<float>(lastMouseY - mouse_y);

        lastMouseX = mouse_x;
        lastMouseY = mouse_y;

        cam->process_mouse_movement(x_offset, y_offset);
    }
}

int main()
{
    
    wizm::renderer::camera_settings camera_settings;
    cam = std::make_unique<wizm::renderer::camera_3d>(camera_settings);
    
    wizm::platform::window_desc desc = {
        "Wizard Machine", 
        1920/2,
        1080/2,
        [](wizm::core::core_event& event) {raise_event(event);}
    };
    
    auto _window = wizm::platform::create_window(desc);

    glfwSetInputMode(reinterpret_cast<GLFWwindow*>(_window->get_native_window()), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        return -1;
    }
    
    glEnable(GL_DEPTH_TEST);
    
    std::vector<wizm::renderer::vertex_data> cube_vertices = {
    // ===== FRONT FACE (+Z) =====
    {{-0.5f, -0.5f,  0.5f}, {0,0,1}, {0,0}, {1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f, -0.5f,  0.5f}, {0,0,1}, {1,0}, {1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f,  0.5f}, {0,0,1}, {1,1}, {1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f,  0.5f}, {0,0,1}, {1,1}, {1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f,  0.5f,  0.5f}, {0,0,1}, {0,1}, {1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f, -0.5f,  0.5f}, {0,0,1}, {0,0}, {1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},

    // ===== BACK FACE (-Z) =====
    {{ 0.5f, -0.5f, -0.5f}, {0,0,-1}, {0,0}, {-1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f, -0.5f, -0.5f}, {0,0,-1}, {1,0}, {-1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f,  0.5f, -0.5f}, {0,0,-1}, {1,1}, {-1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f,  0.5f, -0.5f}, {0,0,-1}, {1,1}, {-1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f, -0.5f}, {0,0,-1}, {0,1}, {-1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f, -0.5f, -0.5f}, {0,0,-1}, {0,0}, {-1,0,0}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},

    // ===== LEFT FACE (-X) =====
    {{-0.5f, -0.5f, -0.5f}, {-1,0,0}, {0,0}, {0,0,1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f, -0.5f,  0.5f}, {-1,0,0}, {1,0}, {0,0,1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f,  0.5f,  0.5f}, {-1,0,0}, {1,1}, {0,0,1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f,  0.5f,  0.5f}, {-1,0,0}, {1,1}, {0,0,1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f,  0.5f, -0.5f}, {-1,0,0}, {0,1}, {0,0,1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f, -0.5f, -0.5f}, {-1,0,0}, {0,0}, {0,0,1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},

    // ===== RIGHT FACE (+X) =====
    {{ 0.5f, -0.5f,  0.5f}, {1,0,0}, {0,0}, {0,0,-1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f, -0.5f, -0.5f}, {1,0,0}, {1,0}, {0,0,-1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f, -0.5f}, {1,0,0}, {1,1}, {0,0,-1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f, -0.5f}, {1,0,0}, {1,1}, {0,0,-1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f,  0.5f}, {1,0,0}, {0,1}, {0,0,-1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f, -0.5f,  0.5f}, {1,0,0}, {0,0}, {0,0,-1}, {0,1,0}, {-1,-1,-1,-1}, {0,0,0,0}},

    // ===== TOP FACE (+Y) =====
    {{-0.5f,  0.5f,  0.5f}, {0,1,0}, {0,0}, {1,0,0}, {0,0,-1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f,  0.5f}, {0,1,0}, {1,0}, {1,0,0}, {0,0,-1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f, -0.5f}, {0,1,0}, {1,1}, {1,0,0}, {0,0,-1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f,  0.5f, -0.5f}, {0,1,0}, {1,1}, {1,0,0}, {0,0,-1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f,  0.5f, -0.5f}, {0,1,0}, {0,1}, {1,0,0}, {0,0,-1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f,  0.5f,  0.5f}, {0,1,0}, {0,0}, {1,0,0}, {0,0,-1}, {-1,-1,-1,-1}, {0,0,0,0}},

    // ===== BOTTOM FACE (-Y) =====
    {{-0.5f, -0.5f, -0.5f}, {0,-1,0}, {0,0}, {1,0,0}, {0,0,1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f, -0.5f, -0.5f}, {0,-1,0}, {1,0}, {1,0,0}, {0,0,1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f, -0.5f,  0.5f}, {0,-1,0}, {1,1}, {1,0,0}, {0,0,1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{ 0.5f, -0.5f,  0.5f}, {0,-1,0}, {1,1}, {1,0,0}, {0,0,1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f, -0.5f,  0.5f}, {0,-1,0}, {0,1}, {1,0,0}, {0,0,1}, {-1,-1,-1,-1}, {0,0,0,0}},
    {{-0.5f, -0.5f, -0.5f}, {0,-1,0}, {0,0}, {1,0,0}, {0,0,1}, {-1,-1,-1,-1}, {0,0,0,0}},
    };
    
    std::vector<unsigned int> cube_indices = {
        0,  1,  2,  3,  4,  5,   // Front
        6,  7,  8,  9, 10, 11,   // Back
       12, 13, 14, 15, 16, 17,   // Left
       18, 19, 20, 21, 22, 23,   // Right
       24, 25, 26, 27, 28, 29,   // Top
       30, 31, 32, 33, 34, 35,   // Bottom
   };
    
    wizm::renderer::core_gl_shader shader{
        "../WizmRender/shaders/vrtx.glsl",
        "../WizmRender/shaders/frgmnt.glsl"
    };
    
    wizm::renderer::core_arr_vertex_buffer vba{cube_vertices, cube_indices};
    vba.bind_buffer();
    vba.create_attrib_arr(0, 3, sizeof(wizm::renderer::vertex_data), offsetof(wizm::renderer::vertex_data, m_position));
    vba.create_attrib_arr(1, 2, sizeof(wizm::renderer::vertex_data), offsetof(wizm::renderer::vertex_data, m_tex_coords));
    vba.create_buffer();
    
    
    
    while (!_window->should_close())
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        shader.use_shader();
        
        cam->update(deltaTime);
        
        shader.setMat4("view", cam->get_view_matrix());
        shader.setMat4("projection", cam->get_projection_matrix());
        
        static float rotation_angle = 0.0f;
        rotation_angle += 0.1f * deltaTime; 
        
        auto model = wizm::math::mat4<float>::identity();
        model = wizm::math::rotate(model, rotation_angle, wizm::math::vec3<float>(0.0f, 1.f, 0.0f));
        model = wizm::math::translate(model, wizm::math::vec3<float>(0.0f, 0.f, 0.0f));
        
        shader.setMat4("model", model);
        
        vba.draw_buffer(static_cast<unsigned int>(cube_indices.size()));
        
        _window->swap_buffers();
        _window->poll_events();
    }
}




