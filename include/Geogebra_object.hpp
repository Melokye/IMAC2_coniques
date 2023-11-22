#pragma once

#include "Geogebra_conics.hpp"
#include <Eigen/Dense>
#include <math.h>
#include <string>

class Geogebra_object {
protected:
  Eigen::VectorXd *m_rep;

public:
  virtual void push(Viewer_conic &v) const {};
  virtual ~Geogebra_object(){};

  /* ----------- non virtual ----------- */
  Geogebra_object(int n = 1) : m_rep(new Eigen::VectorXd(n)){};
  Eigen::VectorXd get_rep() const { return *(this->m_rep); };
  double norm() const {
    double res = 0;
    for (unsigned int i = 0; i < (*m_rep).size(); i++) {
      res += pow((*m_rep)[i], 2);
    }
    return sqrt(res);
  }
};
