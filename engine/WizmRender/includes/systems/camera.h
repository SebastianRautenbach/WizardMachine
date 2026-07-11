#pragma once
#include <cstdint>

namespace wizm
{
    namespace renderer
    {
        
        enum e_camera_type : uint32_t
        {
            e_camera_type_2D = 0,
            e_camera_type_3D,
        };
        
        class camera
        {
            public:
            virtual void update(float delta_time) = 0;
            virtual e_camera_type get_type()=0;
        };
    }    
}
