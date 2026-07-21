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
            explicit camera_3d(const camera_settings& settings);

            void update(float delta_time) override;
            e_camera_type get_type() const override
            {
                return e_camera_type_3D;
            };
        };
    }
}
