#include <glad/glad.h>
#include "platform_window.h"
#include "platform_input.h"
#include <iostream>
#include <ranges>
#include "systems/vertex_buffer.h"
#include "shader/shader.h"
#include "systems/camera_3d.h"

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
    
    
    //std::vector<wizm::renderer::vertex_data> vertexData = {{}};
    //wizm::renderer::core_vertex_buffer temp{vertexData};
    
    wizm::renderer::camera_settings camera_settings;
    wizm::renderer::camera_3d cam{camera_settings};
    
    while (!_window->should_close())
    {
        cam.update(0.f);
        
        _window->swap_buffers();
        _window->poll_events();
    }
}




