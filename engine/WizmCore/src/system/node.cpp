#include "system/node.h"

wizm::core::node::~node()
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