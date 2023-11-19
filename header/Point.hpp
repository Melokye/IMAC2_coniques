#pragma once

#include <Eigen/Dense>
#include <vector>

class Point {
private:
  /* ------------- Membres ------------- */
  Eigen::RowVectorXd matrixEquation = Eigen::RowVectorXd(6);
  double x, y, w;

public:
  /* ------------- Constructeur/Destructeur ------------- */
  Point(const double &x0 = 0, const double &y0 = 0, const bool &fini = 1);
  ~Point();

  /* ------------- Fonctions ------------- */
  inline double getX() const { return x; }
  inline double getY() const { return y; }
  inline double getW() const { return w; }
  inline Eigen::RowVectorXd getMatrixEquation() const {
    return matrixEquation;
  };
};
