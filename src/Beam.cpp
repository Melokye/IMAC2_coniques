
#include "Beam.hpp"

Beam::Beam(Conic c1, Conic c2) {
  for (int i = 0; i < m_approx; i++) {
    double t = 3.141592 / m_approx * i; // pas
    Conic C1(c1);
    C1.set_rep(c1.get_rep()[0], c1.get_rep()[1], c1.get_rep()[2],
               c1.get_rep()[3], c1.get_rep()[4], c1.get_rep()[5]);
  }
}