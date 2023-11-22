
#include "Point.hpp"
#include <Eigen/Dense>
// #include "Eigen/src/Core/Matrix.h"
#include <iostream>

Point::Point(const double &x0, const double &y0, const bool &fini)
    : Geogebra_object(3) {

  *(this->m_rep) << x0, y0, (int)fini;

  matrixEquation << pow((*m_rep)[0], 2), (*m_rep)[0] * (*m_rep)[1],
      pow((*m_rep)[1], 2), (*m_rep)[0] * (*m_rep)[2], (*m_rep)[1] * (*m_rep)[2],
      (*m_rep)[2] * (*m_rep)[2];
}
Point::~Point(){};

void Point::push(Viewer_conic &v) const {
  std::cout << "push point...\n";
  v.push_point((*m_rep), 0, 0, 200);
}