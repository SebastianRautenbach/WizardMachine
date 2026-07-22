#include <glad/glad.h>
#include "platform_window.h"
#include "platform_input.h"
#include <iostream>
#include <ranges>
#include <GLFW/glfw3.h>

#include "system/vertex_buffer.h"
#include "shader/shader.h"
#include "system/camera_3d.h"

#include "math/matrix_transforms.h"


void raise_event(wizm::core::core_event& event)
{
    std::cout << "handled" << event.to_string() << "\n";
}

int main()
{
    wizm::platform::window_desc desc = {
        "Wizard Machine", 
        1920/2,
        1080/2,
        [](wizm::core::core_event& event) {raise_event(event);}
    };
    
    auto _window = wizm::platform::create_window(desc);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return -1;
    }
    
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
    
    wizm::renderer::core_gl_shader shader{"WizardMachine/engine/WizmRender/shaders/vrtx.glsl",
        "WizardMachine/engine/WizmRender/shaders/frgmnt.glsl"};
    
    wizm::renderer::core_arr_vertex_buffer vba{cube_vertices, cube_indices};
    vba.bind_buffer();
    vba.create_attrib_arr(0, 3, sizeof(wizm::renderer::vertex_data), offsetof(wizm::renderer::vertex_data, m_position));
    vba.create_attrib_arr(1, 2, sizeof(wizm::renderer::vertex_data), offsetof(wizm::renderer::vertex_data, m_tex_coords));
    vba.create_buffer();
    
    wizm::renderer::camera_settings camera_settings;
    wizm::renderer::camera_3d cam{camera_settings};
    
    while (!_window->should_close())
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        shader.use_shader();
        
        cam.update(0.f);
        
        shader.setMat4("view", cam.get_view_matrix());
        shader.setMat4("projection", cam.get_projection_matrix());
        
        auto model = wizm::math::mat4<float>::identity();
        model = wizm::math::translate(model, wizm::math::vec3<float>(5.0f, 0.f, 0.0f));
        
        shader.setMat4("model", model);
        
        vba.draw_buffer(static_cast<unsigned int>(cube_indices.size()));
        
        _window->swap_buffers();
        _window->poll_events();
    }
}




