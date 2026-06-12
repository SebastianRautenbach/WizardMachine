#pragma once

#include "core_event.h"
#include <memory>

namespace wizm
{
    namespace core
    {
        class layer
        {
        public:
            layer(const std::string& name = "Layer") : m_debug_name(name) {}
            virtual ~layer() = default;

            virtual void on_event(core_event& event) {}
            
            virtual void on_attach() {} 
            virtual void on_detach() {}

            virtual void on_update(float delta_time) {}
            virtual void on_render() {}
        
            std::string get_layer_name() { return m_debug_name; }
        
        private:
            
        protected:
            std::string m_debug_name;
        };
    }
}



