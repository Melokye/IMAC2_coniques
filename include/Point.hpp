#pragma once

#include "Geogebra_object.hpp"
#include <Eigen/Dense>
#include <vector>

class Point : public Geogebra_object {
private:
  Eigen::RowVectorXd matrix_equation = Eigen::RowVectorXd(6);

public:
  Point(const double &x0 = 0, const double &y0 = 0, const bool &fini = 1);
  Point(const Point &p)
      : Point(p.get_rep()[0], p.get_rep()[1], p.get_rep()[2]) {}

  ~Point();

  /* ------------- Fonctions ------------- */

  inline Eigen::RowVectorXd get_matrix_equation() const {
    return matrix_equation;
  };

  void push(Viewer_conic &v) const override;
};
