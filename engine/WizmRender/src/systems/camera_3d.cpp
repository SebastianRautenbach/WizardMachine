#include "systems/camera_3d.h"

namespace wizm
{
    namespace renderer
    {
        camera_3d::camera_3d(math::vec3<float> tar, math::vec3<float> pos, float fov, float speed, float sens,
            float nearP, float farP)
        {
            
        }

        void camera_3d::update(float delta_time)
        {
            
        }

        e_camera_type camera_3d::get_type()
        {
            return e_camera_type_3D;
        }
    }
}
