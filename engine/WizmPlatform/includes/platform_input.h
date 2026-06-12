#pragma once
#include <format>
#include "math/vec2.h"
#include "system/core_event.h"

namespace wizm
{
    namespace platform
    {
        class key_event : public wizm::core::core_event
        {
        public:
                inline int get_key_code() const {return m_key_code;}
            
        protected:
            key_event(int key_code)
                :m_key_code(key_code) {}
            
            int m_key_code;
        };
        
        
        class key_pressed_event : public key_event
        {
        public:
            key_pressed_event(int key_code, bool is_repeat)
                :key_event(key_code), m_is_repeat(is_repeat)
            {}
            
            inline bool is_repeat() const {return m_is_repeat;}
            
            std::string to_string() const override
            {
                return std::format("key_pressed_event {} (repeat={})", m_key_code, m_is_repeat);
            };
            
            EVENT_CLASS_TYPE(key_press);
            
        private:
            bool m_is_repeat = false;    
        };
        
        
        class key_released_event : public key_event
        {
        public:
            key_released_event(int key_code)
                : key_event(key_code) {}

            std::string to_string() const override
            {
                return std::format("KeyReleasedEvent: {}", m_key_code);
            }

            EVENT_CLASS_TYPE(key_release)
        };
        
        // mouse
        
        
        class mouse_move_event : public core::core_event
        {
        public:
            mouse_move_event(double x, double y)
                : m_mouse_x(x), m_mouse_y(y) {}

            inline double get_x() const { return m_mouse_x; }
            inline double get_y() const { return m_mouse_y; }

            std::string to_string() const override
            {
                return std::format("mouse_move_event: {}, {}", m_mouse_x, m_mouse_y);
            }

            EVENT_CLASS_TYPE(mouse_move)
        private:
            double m_mouse_x, m_mouse_y;
        };

        class mouse_scrolled_event : public core::core_event
        {
        public:
            mouse_scrolled_event(double x_offset, double y_offset)
                : m_x_offset(x_offset), m_y_offset(y_offset) {}

            inline double get_x_offset() const { return m_x_offset; }
            inline double get_y_offset() const { return m_y_offset; }

            std::string to_string() const override
            {
                return std::format("mouse_scrolled_event: {}, {}", m_x_offset, m_y_offset);
            }

            EVENT_CLASS_TYPE(mouse_scroll)
        private:
            double m_x_offset, m_y_offset;
        };

        class mouse_button_event : public core::core_event
        {
        public:
            inline int get_mouse_button() const { return m_button; }
        protected:
            mouse_button_event(int button)
                : m_button(button) {}

            int m_button;
        };

        class mouse_button_pressed_event : public mouse_button_event
        {
        public:
            mouse_button_pressed_event(int button)
                : mouse_button_event(button) {}

            std::string to_string() const override
            {
                return std::format("mouse_button_pressed_event: {}", m_button);
            }

            EVENT_CLASS_TYPE(mouse_button_press)
        };

        class mouse_button_released_event : public mouse_button_event
        {
        public:
            mouse_button_released_event(int button)
                : mouse_button_event(button) {}

            std::string to_string() const override
            {
                return std::format("mouse_button_released_event: {}", m_button);
            }

            EVENT_CLASS_TYPE(mouse_button_release)
        };
    }
}
