#ifndef __GEOGEBRA_OBJECT_HPP__
#define __GEOGEBRA_OBJECT_HPP__

#include "Color.hpp"
#include <string>

class Geogebra_object{
protected:
    std::string m_name;
    Color m_color;

public:
    Geogebra_object(const std::string &name, const Color &color); // TODO = default;
    
    ~Geogebra_object(){}

    inline std::string name() const {return this->m_name;}
    inline Color color() const {return this->m_color;}
    virtual std::string equation() const;
};

#endif