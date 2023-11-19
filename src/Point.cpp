#include "Point.hpp"
#include <Eigen/Dense>
#include <iostream>

#include "Color.hpp"

Point::Point(double x, double y, bool fini, const Color &color) 
: m_x(x), m_y(y), m_w(fini), m_color(color){
  static unsigned int cpt = 0;
  m_matrixEquation << pow(x, 2), x * y, pow(y, 2), x * m_w, y * m_w, m_w;
  m_name = "p" + std::to_string(++cpt);
}

Point::~Point() {}
