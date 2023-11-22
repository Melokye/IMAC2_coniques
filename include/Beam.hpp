#pragma once

#include "Conic.hpp"
#include <Eigen/Dense>
#include <iostream>
#include <vector>

class Beam {

private:
  std::vector<Conic *> conics;
  int m_approx = 30;

public:
  Beam(Conic c1, Conic c2);
};
