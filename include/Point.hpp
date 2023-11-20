#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <Eigen/Dense>
#include <vector>
#include "Geogebra_object.hpp"

class Point : public Geogebra_object {
private:
  Eigen::RowVectorXd m_matrixEquation = Eigen::RowVectorXd(6); // TODO à revoir ?
  double m_x, m_y, m_w;

public:
  Point(const double x = 0, const double y = 0, const bool fini = 1);
    // TODO nécéssaire de définir x,y = 0 ?
  ~Point();

  inline Eigen::RowVectorXd matrixEquation() { return m_matrixEquation;};
  inline double x() { return m_x; }
  inline double y() { return m_y; }
  inline double w() { return m_w; }

  std::string equation() const override;
};



#endif