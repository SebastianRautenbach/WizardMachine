#pragma once
#include <string>

namespace wizmcore
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

