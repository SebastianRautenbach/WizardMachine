#include "system/node.h"
#include "math/matrix_transform.h"
#include "math/quat_utils.h"
#include "math/type_conver.h"
namespace wizmcore {

	core_node::core_node()
		:m_translation(0.0f), m_rotation(0.0f), m_scale(1.0f)
	{
	}

	core_node::~core_node()
	{
		while (!m_child_nodes.empty()) {
			auto ent = m_child_nodes.back();

			m_child_nodes.pop_back();

			delete ent;
		}

		if (m_parent_node) {
			auto& siblings = m_parent_node->m_child_nodes;
			siblings.erase(std::remove(siblings.begin(), siblings.end(), this), siblings.end());
		}
	}

	void core_node::add_parent(core_node* parent_node)
	{
		if (m_parent_node)
			m_parent_node->remove_child(this);

		m_parent_node = parent_node;
		m_parent_node->add_child(this);
	}

	void core_node::remove_parent()
	{
		if (m_parent_node)
		{
			m_parent_node->remove_child(this);
			m_parent_node = nullptr;
		}
	}

	void core_node::add_child(core_node* child_node)
	{
		m_child_nodes.emplace_back(child_node);
	}

	std::vector<core_node*>& core_node::get_children()
	{
		return m_child_nodes;
	}

	void core_node::remove_child(core_node* entity)
	{
		if (m_child_nodes.empty()) { return; }
		m_child_nodes.erase(std::remove(m_child_nodes.begin(), m_child_nodes.end(), entity), m_child_nodes.end());
	}

	void core_node::set_position(const math::vec3<float>& position)
	{
		m_translation = position;
	}

	void core_node::add_position(const math::vec3<float>& offset)
	{
		m_translation += offset;
	}

	void core_node::set_rotation(const math::vec3<float>& rotation)
	{
		m_rotation = rotation;
	}

	void core_node::add_rotation(const math::vec3<float>& deltaRotation)
	{
		m_rotation += deltaRotation;
	}

	void core_node::set_scale(const math::vec3<float>& scale)
	{
		m_scale = scale;
	}

	void core_node::add_scale(const math::vec3<float>& deltaScale)
	{
		m_scale += deltaScale;
	}

	math::mat4<float> core_node::get_world_transform()
	{
		static const math::mat4<float> identity = math::mat4<float>(1.0f);
		
		math::mat4<float> rotation = math::q_to_mat4(math::quat<float>(m_rotation));

		math::mat4<float> localTransform = math::translate(identity, m_translation) *
			rotation *
			math::scale(identity, m_scale);

		if (!m_parent_node) {
			return localTransform;
		}

		return m_parent_node->get_world_transform() * localTransform;
	}

	math::vec3<float> core_node::get_world_position()
	{
		if (m_parent_node)
			return math::vec3<float>(math::v4ToV3(m_parent_node->get_world_transform() * 
				math::vec4<float>(m_translation.x, m_translation.y, m_translation.z, 1.0f)));
		else
			return m_translation;
	}

	math::vec3<float> core_node::get_direction()
	{
		return math::vec3<float>();
	}

	math::mat4<float> core_node::get_rotation_matrix()
	{
		return math::mat4<float>();
	}

	math::vec3<float> core_node::get_world_rotation()
	{
		return math::vec3<float>();
	}

	math::quat<float> core_node::get_world_rotation_quat()
	{
		return math::quat<float>();
	}

	math::vec3<float> core_node::get_world_scale()
	{
		return math::vec3<float>();
	}


}


