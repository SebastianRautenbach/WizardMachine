#pragma once
#include <string>

namespace wizm
{
    
    namespace core
    {
        class tag
        {
        public:
            std::string& get_tag() {return m_tag;}
            void set_tag(std::string const& tag) {m_tag = tag;}
    
        private:
            std::string m_tag;
        };        
    }
}

