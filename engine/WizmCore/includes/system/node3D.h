#pragma once
#include "node.h"
#include "math/pch_math.h"

namespace wizmcore
{
    class node3D : public core_node
    {
    public:
        
        //---------------------------------------------------------------------------------- TRANSFORM

        // Setters
        void set_position(const glm::vec3& position);
        void add_position(const glm::vec3& offset);
        void set_rotation(const glm::vec3& rotation);
        void add_rotation(const glm::vec3& deltaRotation);
        void set_scale(const glm::vec3& scale);
        void add_scale(const glm::vec3& deltaScale);
        void move_forward(const float distance);
        void move_right(const float distance);
        void move_up(const float distance);
        void make_transform_dirty() { m_is_dirty = true; }
        void clear_dirty_transform() { m_is_dirty = false; }
        
        // Getters
        const glm::vec3& get_position() const { return m_translation; }	
        const glm::vec3& get_rotation() const { return m_rotation; }		
        const glm::vec3& get_scale() const { return m_scale; }				
        const glm::mat4& get_transform() const { return m_transform; }		
        const glm::vec3& get_up_vector() const { return m_up; }
        const glm::vec3& get_right_vector() const { return m_right; }
        const glm::vec3& get_forward_vector() const { return m_forward; }
        bool is_dirty() { return m_is_dirty; }
        
    private:
        glm::vec3 m_translation;
        glm::vec3 m_rotation;
        glm::vec3 m_scale;
        glm::mat4 m_transform;
        
        glm::vec3 m_up = { 0.0f, 1.0f, 0.0f };
        glm::vec3 m_right = { 1.0f, 0.0f, 0.0f };
        glm::vec3 m_forward = { 0.0f, 0.0f, -1.0f };
        
        bool m_is_dirty = true;
    };
}


