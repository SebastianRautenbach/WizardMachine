#include "../includes/system/layer_stack.h"


wizm::core::layer_stack::~layer_stack()
{
    for (layer* layer : m_layers) {
        layer->on_detach();
        delete layer;
    }
  
}


//----------------------------------------------------------------------

void wizm::core::layer_stack::push_layer(layer* layer)
{
    m_layers.emplace_back(layer);
    layer->on_attach();
}

void wizm::core::layer_stack::pop_layer(layer* layer)
{
    auto it = std::find(m_layers.begin(), m_layers.end(), layer);
    if (it != m_layers.end()) {
        (*it)->on_detach();
        m_layers.erase(it);
    }
}