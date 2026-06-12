#pragma once


#include <string>
#include <functional>

namespace wizm
{
    namespace core
    {
        enum class event_type
        {
            none = 0,
            window_resize, window_close,
            key_press, key_release,
            mouse_button_press, mouse_button_release, mouse_move, mouse_scroll,
        };
    
#define EVENT_CLASS_TYPE(type) static core::event_type get_static_type() { return core::event_type::type; }\
                               virtual core::event_type get_event_type() const override { return get_static_type(); }\
                               virtual const char* get_name() const override { return #type; }
        
        
        class core_event
        {
        public:
            bool is_handled = false;
            virtual event_type get_event_type() const = 0;
            virtual const char* get_name() const = 0;
            virtual std::string to_string() const {return get_name();}
        };
        
        
        class event_dispatcher
        {
            template<typename T>
            using event_func = std::function<bool(T&)>;
            
        public:
            event_dispatcher(core_event& event)
                : m_event(event)
            {}
            
            template<typename T>
            bool dispatch(event_func<T> func)
            {
                if (m_event.get_event_type() == T::get_static_type() && !m_event.is_handled)
                {
                    m_event.is_handled = func(*(T*)&m_event);
                    return true;
                }
            }            
            
        private:
            core_event& m_event;
        };
        
        
        
    }
}



