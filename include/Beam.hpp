#pragma once

#include "Conic.hpp"
#include <vector>

class Beam {

private:
  std::vector<Conic *> m_conics;
  const unsigned int m_approx = 20;

public:
  Beam(Conic c1, Conic c2);
  std::vector<Conic *> get_conics() const;
};
