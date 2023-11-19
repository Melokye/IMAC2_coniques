#include "Conic.hpp"
#include <Eigen/Dense>
#include <cstdarg>
#include <cstdio>
#include <stdexcept>

Conic::~Conic() {}

Type Conic::conicType() const {

  if (coeff[0] == coeff[2] && coeff[1] == 0)
    return Type::cercle;
  double root = pow(coeff[1], 2) - 4 * coeff[0] * coeff[2];
  return root == 0  ? Type::parabole
         : root < 0 ? Type::ellipse
                    : Type::hyperbole;
}
