#include "system/node.h"
#include "ZER/ZER.h"

wizmcore::core_node::~core_node()
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

void wizmcore::core_node::add_parent(core_node* parent_node)
{
    if(m_parent_node)
        m_parent_node->remove_child(this);

    m_parent_node = parent_node;
    m_parent_node->add_child(this);
}

void wizmcore::core_node::remove_parent()
{
    if (m_parent_node)
    {
        m_parent_node->remove_child(this);
        m_parent_node = nullptr;
    }
}

void wizmcore::core_node::add_child(core_node* child_node)
{
    child_node->add_parent(this);
    m_child_nodes.emplace_back(child_node);
}

void wizmcore::core_node::remove_child(core_node* child_node)
{
    if (m_child_nodes.empty()) { return; }
    m_child_nodes.erase(std::remove(m_child_nodes.begin(), m_child_nodes.end(), child_node), m_child_nodes.end());
}

void wizmcore::core_node::remove_all_children()
{
    m_child_nodes.clear();
}

wizmcore::core_node* wizmcore::core_node::get_parent()
{
    return m_parent_node;
}

std::vector<wizmcore::core_node*> wizmcore::core_node::get_children()
{
    return m_child_nodes;
}

void wizmcore::core_node::save_data(std::string parent_name, std::string index, filedata::ZER& save_t) const
{
}

void wizmcore::core_node::read_saved_data(std::string parent_name, std::string index, filedata::ZER& save_t)
{
}
