#include "Conic.hpp"
#include <Eigen/Dense>
#include <cstdarg>
#include <cstdio>
#include <stdexcept>

Conic::~Conic() {}

Type Conic::conicType() const {

  if ((*m_rep)[0] == (*m_rep)[2] && (*m_rep)[1] == 0)
    return Type::cercle;
  double root = pow((*m_rep)[1], 2) - 4 * (*m_rep)[0] * (*m_rep)[2];
  return root == 0  ? Type::parabole
         : root < 0 ? Type::ellipse
                    : Type::hyperbole;
}

void Conic::push(Viewer_conic &v) const { v.push_conic((*m_rep), 255, 0, 100); }