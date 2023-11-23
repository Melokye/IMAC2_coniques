#pragma once

#include "Geogebra_conics.hpp"
#include <Eigen/Dense>
#include <math.h>
#include <string>

class Geogebra_object {
protected:
  Eigen::VectorXd *m_rep;
  unsigned int m_red;
  unsigned int m_green;
  unsigned int m_blue;

public:
  virtual ~Geogebra_object(){};
  virtual void push([[maybe_unused]] Viewer_conic &v) const {};

  /* ----------- non virtual ----------- */
  Geogebra_object(int n = 1, 
    unsigned int red = 0, unsigned int green = 0, unsigned int blue = 0)
    : m_rep(new Eigen::VectorXd(n)),
      m_red(red), m_green(green), m_blue(blue){};

  Eigen::VectorXd get_rep() const { return *(this->m_rep); };

  double norm() const {
    double res = 0;
    for (unsigned int i = 0; i < (*m_rep).size(); i++) {
      res += pow((*m_rep)[i], 2);
    }
    return sqrt(res);
  }

  void setColor(unsigned int red, unsigned int green, unsigned int blue) {
    m_red = red;
    m_blue = blue;
    m_green = green;
  }
};
