
#include "Point.hpp"
#include "Eigen/src/Core/Matrix.h"
#include <iostream>

Point::Point(const double &x0, const double &y0, const bool &fini) {
  x = x0;
  y = y0;
  w = fini;

  matrixEquation << pow(x, 2), x * y, pow(y, 2), x * w, y * w, w * w;
}

Point::~Point(){};