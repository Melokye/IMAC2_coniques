#include "Point.hpp"
#include "Color.hpp"

static unsigned int m_cpt = 0; // TODO dans constructeur

Point::Point(double x, double y, bool fini) 
: Geogebra_object("p" + std::to_string(m_cpt++), Color(200,0,0)), m_x(x), m_y(y), m_w(fini){
  m_matrixEquation << pow(x, 2), x * y, pow(y, 2), x * m_w, y * m_w, m_w;
}

Point::~Point() {}

std::string Point::equation() const{
  return " Point({" + std::to_string(m_x) + "," + std::to_string(m_y) + "})";
  // TODO : cas point à l'infini ?
}