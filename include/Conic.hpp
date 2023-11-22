#pragma once
#include "Point.hpp"

#include <Eigen/Dense>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

enum Type { cercle, ellipse, parabole, hyperbole };

class Conic : public Geogebra_object {
private:
  /* -------------- Membres -------------- */

  /* ------------- Fonctions ------------- */

  template <class Arg>
  void addMatrix(Eigen::MatrixXd &m, const Arg &arg) const {
    m.conservativeResize(m.rows() + 1, m.cols());
    m.row(m.rows() - 1) = arg.getMatrixEquation();
  }

  template <class Arg, class... Args>
  void addMatrix(Eigen::MatrixXd &m, const Arg &arg,
                 const Args &...args) const {
    addMatrix(m, arg);
    addMatrix(m, args...);
  }

public:
  /* -------------- Membres -------------- */

  /* ----- Constructeur/Destructeur ----- */

  Conic(const Conic &c) : Geogebra_object(6) { *(m_rep) = *(c.m_rep); };

  template <class... Args> Conic(const Args... args) : Geogebra_object(6) {
    int numPoints = sizeof...(args);
    if (numPoints < 5)
      throw std::logic_error("Number of points should be even and at least 5.");

    Eigen::MatrixXd A(0, 6);
    addMatrix(A, args...);
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU |
                                                 Eigen::ComputeFullV);
    *(m_rep) = svd.matrixV().rightCols(1);
  }
  ~Conic();

  /* ------------- Fonctions ------------- */
  Type conicType() const;
  void push(Viewer_conic &v) const override;
};
