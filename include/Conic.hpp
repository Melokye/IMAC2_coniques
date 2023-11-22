#pragma once
#include "Point.hpp"

#include <Eigen/Dense>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

enum Type { cercle, ellipse, parabole, hyperbole };
class Conic : public Geogebra_object {

  friend class Beam;

private:
  template <class Arg>
  void add_matrix(Eigen::MatrixXd &m, const Arg &arg) const {
    m.conservativeResize(m.rows() + 1, m.cols());
    m.row(m.rows() - 1) = arg.get_matrix_equation();
  }

  template <class Arg, class... Args>
  void add_matrix(Eigen::MatrixXd &m, const Arg &arg,
                  const Args &...args) const {
    add_matrix(m, arg);
    add_matrix(m, args...);
  }

protected:
  void set_rep(double a, double b, double c, double d, double e, double f);

public:
  template <class... Args>
  Conic(const Args... args) : Geogebra_object(6, 255, 0, 100) {
    int num_points = sizeof...(args);
    if (num_points < 5)
      throw std::logic_error("Number of points should be even and at least 5.");

    Eigen::MatrixXd A(0, 6);
    add_matrix(A, args...);
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU |
                                                 Eigen::ComputeFullV);
    *(m_rep) = svd.matrixV().rightCols(1);
  }

  Conic(const Conic &c);
  ~Conic();

  Type conic_type() const;
  void push(Viewer_conic &v) const override;
  void beam(Conic c) const;
};
