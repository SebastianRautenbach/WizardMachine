#pragma once
#include <string>
#include <vector>

namespace filedata
{
	class ZER;
}

namespace wizmcore {
	
	class save_node
	{
	public:
		virtual void save_data(std::string parent_name, std::string index, filedata::ZER& save_t) const = 0;
		virtual void read_saved_data(std::string parent_name, std::string index, filedata::ZER& save_t) = 0;
	};
	
	
	class core_node : public save_node {
	public:
		

		core_node() = default;
		~core_node();
	
	public:
		void add_parent(core_node* parent_node);
		void remove_parent();
		
		void add_child(core_node* child_node);
		void remove_child(core_node* child_node);
		
		core_node* get_parent();
		std::vector<core_node*> get_children();
		
		
		void save_data(std::string parent_name, std::string index, filedata::ZER& save_t) const override;
		void read_saved_data(std::string parent_name, std::string index, filedata::ZER& save_t) override;
		
	private:
		core_node* m_parent_node = nullptr;
		std::vector<core_node*> m_child_nodes;
	
	};
}