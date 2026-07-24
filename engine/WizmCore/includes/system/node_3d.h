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
            
            math::vec3<float> m_position = {0.f, 0.f, 0.f};
            math::vec3<float> m_rotation = {0.f, 0.f, 0.f};
            math::vec3<float> m_scale = {0.f, 0.f, 0.f};
            
            math::vec3<float> m_front = {0.f, 0.f, 0.f};
            math::vec3<float> m_right = {0.f, 0.f, 0.f};
            math::vec3<float> m_up = {0.0f, 1.0f, 0.0f};
            
        public:
            void set_position(const math::vec3<float>& position);
            void set_rotation(const math::vec3<float>& rotation);
            void set_scale(const math::vec3<float>& scale);
            
            void add_position(const math::vec3<float>& position);
            void add_rotation(const math::vec3<float>& rotation);
            void add_scale(const math::vec3<float>& scale);
        };
    }
}
