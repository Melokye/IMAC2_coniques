#pragma once
#include "Point.hpp"

#include <Eigen/Dense>
#include <initializer_list>
#include <vector>
enum Type { cercle, ellipse, parabole, hyperbole };

class Conic {
private:
  /* -------------- Membres -------------- */
  Eigen::VectorXd coeff;
  /* ------------- Fonctions ------------- */
  void addMatrix(Point p, Eigen::MatrixXd &m);

public:
  /* -------------- Membres -------------- */

  /* ----- Constructeur/Destructeur ----- */
  Conic(std::vector<Point> points);
  ~Conic();

  /* ------------- Fonctions ------------- */
  Type conicType();
  inline Eigen::VectorXd getCoeff() { return coeff; };
};
