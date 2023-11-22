#pragma once

#include "Geogebra_conics.hpp"
#include <Eigen/Dense>
#include <string>

class Geogebra_object {
protected:
  Eigen::VectorXd *m_rep;

public:
  Geogebra_object(int n = 1)
      : m_rep(new Eigen::VectorXd(n)){}; // TODO = default;

  virtual void push(Viewer_conic &v) const {};
  virtual ~Geogebra_object(){};

  Eigen::VectorXd get_rep() const { return *(this->m_rep); };
  // inline std::string name() const { return this->m_name; }
  //  inline Color color() const { return this->m_color; }
  //  virtual std::string equation() const;
};
