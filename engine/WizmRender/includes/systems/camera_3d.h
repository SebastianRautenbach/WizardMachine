#pragma once
#include "camera.h"
#include "math/math_pch.h"

namespace wizm
{
    namespace renderer
    {
        class camera_3d : public camera
        {
        public:
            
            camera_3d(
                math::vec3<float> tar, 
                math::vec3<float> pos,
                float fov,
                float speed,
                float sens,
                float nearP,
                float farP
                );
            
            void update(float delta_time) override;
            e_camera_type get_type() override;
        };
    }
}
