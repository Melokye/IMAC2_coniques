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
  Point(double x0 = 0, double y0 = 0, bool fini = 1);
  ~Point();

  /* ------------- Fonctions ------------- */
  inline double getX() { return x; }
  inline double getY() { return y; }
  inline double getW() { return w; }
  inline Eigen::RowVectorXd getMatrixEquation() { return matrixEquation; };
};
