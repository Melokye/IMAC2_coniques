#ifndef __CONIC_HPP__
#define __CONIC_HPP__

#include "Point.hpp"

#include <Eigen/Dense>
#include <initializer_list>
#include <vector>
enum Type { cercle, ellipse, parabole, hyperbole }; // TODO je crois qu'il y a meilleure façon

class Conic : public Geogebra_object{
private:
  Eigen::VectorXd m_coeff;
  
private:
  void addMatrix(const Point &p, Eigen::MatrixXd &m);

public:
  Conic(const std::vector<Point> &points);
  ~Conic();

  Type conicType();
  inline Eigen::VectorXd coeff() const { return m_coeff; };
  std::string equation() const override;
};

#endif