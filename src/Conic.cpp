#include "Conic.hpp"
#include <Eigen/Dense>
#include <cstdarg>
#include <cstdio>
#include <stdexcept>

Conic::~Conic() {}

Conic::Conic(const Conic &c)
    : Geogebra_object(6, c.m_red, c.m_green, c.m_blue) {
  *(m_rep) = *(c.m_rep);
};

Type Conic::conic_type() const {

  if ((*m_rep)[0] == (*m_rep)[2] && (*m_rep)[1] == 0)
    return Type::cercle;
  double root = pow((*m_rep)[1], 2) - 4 * (*m_rep)[0] * (*m_rep)[2];
  return root == 0  ? Type::parabole
         : root < 0 ? Type::ellipse
                    : Type::hyperbole;
}

void Conic::push(Viewer_conic &v) const {
  std::cout << "push conic type " << conic_type() << " ...\n";
  v.push_conic((*m_rep), m_red, m_green, m_blue);
}

void Conic::set_rep(double a, double b, double c, double d, double e,
                    double f) {
  (*m_rep)[0] = a;
  (*m_rep)[1] = b;
  (*m_rep)[2] = c;
  (*m_rep)[3] = d;
  (*m_rep)[4] = e;
  (*m_rep)[5] = f;
}

void Conic::add_point(Point point){
  add_matrix(point);
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(m_matrix, Eigen::ComputeThinU |
                                                 Eigen::ComputeFullV);
  *(m_rep) = svd.matrixV().rightCols(1);
}

Conic& Conic::operator=(const Conic &c){

  if(this != &c){
    m_rep = c.m_rep;
    m_red = c.m_red;
    m_green = c.m_green;
    m_blue = c.m_blue;
    
    m_matrix = c.m_matrix;
  }
  return *this;
}