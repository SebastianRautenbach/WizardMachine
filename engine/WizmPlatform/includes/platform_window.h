#pragma once
#include <memory>

#include "system/core_event.h"

namespace wizm
{
    namespace platform
    {
        struct window_desc
        {
            const char* m_title = "Engine";
            uint32_t m_width = 1280;
            uint32_t m_height = 720;
            
            using event_callback_func = std::function<void(core::core_event&)>;
            event_callback_func event_callback;
        };
    
    
        class platform_window
        {
        public:
        
            virtual ~platform_window() = default;

            virtual void poll_events() = 0;
            virtual void swap_buffers() = 0;
            virtual bool should_close() const = 0;

            virtual uint32_t get_width() const = 0;
            virtual uint32_t get_height() const = 0;
        
            virtual float get_time() const = 0;
            virtual void* get_native_window() const = 0;
            
            virtual void raise_event(core::core_event& event) const = 0;
            
            window_desc m_desc;
        };
    
        platform_window* create_window(window_desc const& desc);
    }
}


