#pragma once
#include "platform_window.h"

struct GLFWwindow;

namespace wizm
{
    namespace platform
    {
        class glfw_platform_window : public platform_window
        {
        public:

            glfw_platform_window(window_desc const& desc);
            ~glfw_platform_window() override;

            void raise_event(core::core_event& event) const override;
    
            void poll_events() override;
            void swap_buffers() override;
            bool should_close() const override;
            uint32_t get_width() const override;
            uint32_t get_height() const override;
            void* get_native_window() const override;
            float get_time() const override;
        
        
        private:
            GLFWwindow* m_window;
        };    
    }
}


