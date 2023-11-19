#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <Eigen/Dense>
#include <vector>

class Point {
private:
  Eigen::RowVectorXd matrixEquation = Eigen::RowVectorXd(6);
  double x, y, w;

public:
  Point(double x0 = 0, double y0 = 0, bool fini = 1);
  ~Point();

  inline double getX() { return x; }
  inline double getY() { return y; }
  inline double getW() { return w; }
  inline Eigen::RowVectorXd getMatrixEquation() { return matrixEquation; };
};

#endif