#include "Conic.hpp"
#include <Eigen/Dense>
#include <cstdarg>
#include <cstdio>
#include <iostream>

Conic::Conic(std::vector<Point> points) {
  assert(points.size() >= 5);

  Eigen::MatrixXd A = Eigen::MatrixXd(0, 6);
  for (Point p : points)
    addMatrix(p, A);

  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen ::ComputeThinU |
                                                 Eigen ::ComputeFullV);
  coeff = svd.matrixV().rightCols(1);
}

Conic::~Conic(){};

Type Conic::conicType() {

  if (coeff[0] == coeff[2] && coeff[1] == 0) 
    return Type::cercle;
  double root = pow(coeff[1], 2) - 4 * coeff[0] * coeff[2];
  return root == 0  ? Type::parabole
         : root < 0 ? Type::ellipse
                    : Type::hyperbole;
}

void Conic::addMatrix(Point p, Eigen::MatrixXd &m) {
  m.conservativeResize(m.rows() + 1, m.cols());
  m.row(m.rows() - 1) = p.matrixEquation();
}