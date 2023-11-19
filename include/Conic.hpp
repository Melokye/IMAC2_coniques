#ifndef __CONIC_HPP__
#define __CONIC_HPP__

#include "Point.hpp"

#include <Eigen/Dense>
#include <initializer_list>
#include <vector>
enum Type { cercle, ellipse, parabole, hyperbole };

class Conic {
private:
  Eigen::VectorXd coeff;
  
private:
  void addMatrix(Point p, Eigen::MatrixXd &m);

public:
  Conic(std::vector<Point> points);
  ~Conic();

  Type conicType();
  inline Eigen::VectorXd getCoeff() { return coeff; };
};

#endif