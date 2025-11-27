#pragma once
#include "math/vec3.h"
#include "math/mat4.h"
#include "math/quat.h"
#include <vector>

namespace wizmcore {
	class core_node {
	public:

		core_node();
		virtual ~core_node();
		void add_parent(core_node* parent_node);
		void remove_parent();
		void add_child(core_node* child_node);
		std::vector<core_node*>& get_children();
		void remove_child(core_node* entity);
		core_node* get_parent() { return m_parent_node; }



		// Setters
		void set_position(const math::vec3<float>& position);
		void add_position(const math::vec3<float>& offset);
		void set_rotation(const math::vec3<float>& rotation);
		void add_rotation(const math::vec3<float>& deltaRotation);
		void set_scale(const math::vec3<float>& scale);
		void add_scale(const math::vec3<float>& deltaScale);


		// Getters
		const math::vec3<float>& get_position() const { return m_translation; }	   // <<  These are local transforms
		const math::vec3<float>& get_rotation() const { return m_rotation; }		   // <<  These are local transforms
		const math::vec3<float>& get_scale() const { return m_scale; }				   // <<  These are local transforms
		const math::mat4<float>& get_transform() const { return m_transform; }		   // <<  These are local transforms


		math::mat4<float> get_world_transform();
		math::vec3<float> get_world_position();
		math::vec3<float> get_direction();
		math::mat4<float> get_rotation_matrix();
		math::vec3<float> get_world_rotation();
		math::quat<float> get_world_rotation_quat();
		math::vec3<float> get_world_scale();


	private:
		math::vec3<float> m_translation;
		math::vec3<float> m_rotation;
		math::vec3<float> m_scale;
		math::mat4<float> m_transform;

	private:
		core_node* m_parent_node = nullptr;
		std::vector<core_node*> m_child_nodes;

	};
}