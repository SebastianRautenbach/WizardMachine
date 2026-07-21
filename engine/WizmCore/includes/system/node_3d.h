#pragma once
#include "node.h"
#include "math/vec3.h"

namespace wizm
{
    namespace core
    {
        class node_3d : public node
        {
        public:
            node_3d();
            
            math::vec3<float> m_position;
            math::vec3<float> m_rotation;
            math::vec3<float> m_scale;
            
            math::vec3<float> m_front;
            math::vec3<float> m_right;
            math::vec3<float> m_up = { 0.0f, 1.0f, 0.0f };
        };
    }
}
