#pragma once
#include "layer.h"
#include <vector>

namespace wizm {
    namespace core
    {
        class layer_stack {
        public:
            layer_stack() = default;
            ~layer_stack();

            void push_layer(layer* layer);
            void pop_layer(layer* layer);

            std::vector<layer*>::iterator begin() { return m_layers.begin(); }
            std::vector<layer*>::iterator end() { return m_layers.end(); }

            std::vector<layer*>::const_iterator begin() const { return m_layers.begin(); }
            std::vector<layer*>::const_iterator end() const { return m_layers.end(); }

            std::vector<layer*>::const_reverse_iterator rbegin() const { return m_layers.rbegin(); }
            std::vector<layer*>::const_reverse_iterator rend() const { return m_layers.rend(); }

        public:
            std::vector<layer*> m_layers;
        };
    }
}
