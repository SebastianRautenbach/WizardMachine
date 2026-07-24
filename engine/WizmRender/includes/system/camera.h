#pragma once
#include <cstdint>

#include "math/vec3.h"

namespace wizm
{
    namespace renderer
    {
        
        struct camera_settings
        {
            float near = 0.1f;
            float far = 10000.f;
            float speed = 2.5f;
            float sensitivity = 0.1f;
            float fov = 45.0f;
            float aspect = 1.0f;
        };
        
        enum e_camera_type : uint32_t
        {
            e_camera_type_2D = 0,
            e_camera_type_3D,
        };
        
        class camera
        {
        public:
            camera(camera_settings settings);
            virtual ~camera() = default;
            
            virtual void update(float delta_time) = 0;
            
            virtual e_camera_type get_type() const = 0;
            
        protected:
            camera_settings m_settings;
            
        };
    }    
}
