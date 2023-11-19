#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <Eigen/Dense>
#include <vector>

class Point {
private:
  Eigen::RowVectorXd m_matrixEquation = Eigen::RowVectorXd(6);
  double m_x, m_y, m_w;

public:
  Point(double x0 = 0, double y0 = 0, bool fini = 1);
  ~Point();

  inline double getX() { return m_x; }
  inline double getY() { return m_y; }
  inline double getW() { return m_w; }
  inline Eigen::RowVectorXd getMatrixEquation() { return m_matrixEquation; };
};

#endif