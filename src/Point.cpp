
#include "Point.hpp"
#include <Eigen/Dense>
#include <iostream>

Point::Point(double x, double y, bool fini) 
: m_x(x), m_y(y), m_w(fini) {
  m_matrixEquation << pow(x, 2), x * y, pow(y, 2), x * m_w, y * m_w, m_w * m_w;
}

Point::~Point() {}
