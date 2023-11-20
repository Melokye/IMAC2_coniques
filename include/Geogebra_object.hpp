#ifndef __GEOGEBRA_OBJECT_HPP__
#define __GEOGEBRA_OBJECT_HPP__

#include "Color.hpp"
#include <string>

class Geogebra_object{
protected:
    std::string m_name;
    Color m_color;

public:
    Geogebra_object(std::string name, Color color)
    : m_name(name), m_color(color){}

    ~Geogebra_object(){}

    inline std::string name() const {return this->m_name;}
    inline Color color() const {return this->m_color;}
    virtual std::string equation() const;
};

#endif