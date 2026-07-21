#pragma once
#include <string>
#include <vector>
#include "ZER/ZER.h"

namespace wizm
{
    namespace core
    {
        class save_node {

            virtual void save_data(std::string parent_name, std::string index, filedata::ZER& save_t) const = 0;
            virtual void read_saved_data(std::string parent_name, std::string index, filedata::ZER& save_t) = 0;
        };
        
        class node : public save_node
        {
        public:
            node() {};
            virtual ~node();
            
            //----------------------------------------------------------------------------------

            void add_parent(node* parent_node) {
			
                if(m_parent_node)
                    m_parent_node->remove_child(this);

                m_parent_node = parent_node;
                m_parent_node->add_child(this);
            }

            void remove_parent() {
                if (m_parent_node)
                {
                    m_parent_node->remove_child(this);
                    m_parent_node = nullptr;
                }
            }

            void add_child(node* child_node) {
                m_child_nodes.emplace_back(child_node);
            }

            node* get_parent() { return m_parent_node; }

            std::vector<node*>& get_children() {
                return m_child_nodes;
            }

            void remove_child(node* entity) {
                if (m_child_nodes.empty()) { return; }
                m_child_nodes.erase(std::remove(m_child_nodes.begin(), m_child_nodes.end(), entity), m_child_nodes.end());
            }
            
            void save_data(std::string parent_name, std::string index, filedata::ZER& save_t) const override {}
            void read_saved_data(std::string parent_name, std::string index, filedata::ZER& save_t) override {};
            
        private:
            node* m_parent_node = nullptr;
            std::vector<node*> m_child_nodes;
        };
    }
}



