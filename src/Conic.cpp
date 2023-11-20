#include "Conic.hpp"
#include <Eigen/Dense>
#include <cstdarg>
#include <cstdio>
#include <iostream>

Conic::Conic(const std::vector<Point> &points)
: Geogebra_object("c", Color(100, 0, 200))
{
  assert(points.size() >= 5);

  Eigen::MatrixXd A = Eigen::MatrixXd(0, 6); // TODO à renommer ?
  for (Point p : points)
    addMatrix(p, A);

  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen ::ComputeThinU |
                                               Eigen ::ComputeFullV);
  m_coeff = svd.matrixV().rightCols(1);
}

Conic::~Conic(){};

Type Conic::conicType()
{
  if (m_coeff[0] == m_coeff[2] && m_coeff[1] == 0)
    return Type::cercle;
  double root = pow(m_coeff[1], 2) - 4 * m_coeff[0] * m_coeff[2];
  return root == 0  ? Type::parabole
         : root < 0 ? Type::ellipse
                    : Type::hyperbole;
}

void Conic::addMatrix(Point p, Eigen::MatrixXd &m)
{
  m.conservativeResize(m.rows() + 1, m.cols());
  m.row(m.rows() - 1) = p.matrixEquation();
}

std::string Conic::equation() const{
  return " Conic(" + std::to_string(m_coeff[0]) + "," // x^2
         + std::to_string(m_coeff[2]) + ","           // y^2
         + std::to_string(m_coeff[5]) + ","           // g
         + std::to_string(m_coeff[1]) + ","           // xy
         + std::to_string(m_coeff[3]) + ","           // x
         + std::to_string(m_coeff[4])                 // y
         + ")";
}