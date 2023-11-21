#include "Geogebra_object.hpp"

Geogebra_object::Geogebra_object(const std::string &name, const Color &color)
: m_name(name), m_color(color){
      // remove space in the name
      // m_name.erase(std::remove(m_name.begin(), m_name.end(), ' '), m_name.end()); 
      // TODO à débug
  }

std::string Geogebra_object::equation() const{
  return "Missing Info"; // TODO ?
}


