#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <Eigen/Dense>
#include <vector>
#include "Color.hpp"
class Point {
private:
  Eigen::RowVectorXd m_matrixEquation = Eigen::RowVectorXd(6); // TODO à revoir ?
  double m_x, m_y, m_w;
  Color m_color;

public:
  Point(const double x = 0, const double y = 0, const bool fini = 1, const Color &color = Color(200,0,0));
    // TODO nécéssaire de définir x,y = 0 ?
  ~Point();

  inline double x() { return m_x; }
  inline double y() { return m_y; }
  inline double w() { return m_w; }
  inline Eigen::RowVectorXd matrixEquation() { return m_matrixEquation; };
};

#endif