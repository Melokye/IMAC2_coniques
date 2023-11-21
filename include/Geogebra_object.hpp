#ifndef __GEOGEBRA_OBJECT_HPP__
#define __GEOGEBRA_OBJECT_HPP__

#include "Color.hpp"
#include <string>

class Geogebra_object{
protected:
    std::string m_name;
    Color m_color;

public:
    Geogebra_object(std::string name, Color color) // TODO default
    : m_name(name), m_color(color){
        // remove space in the name
        m_name.erase(std::remove(m_name.begin(), m_name.end(), ' '), m_name.end()); 
    }

    ~Geogebra_object(){}

    inline std::string name() const {return this->m_name;}
    inline Color color() const {return this->m_color;}
    virtual std::string equation() const;
};

#endif