
#include "Beam.hpp"
#include <numbers>

Beam::Beam(Conic c1, Conic c2) {
  Conic _c(c1);
  Conic _c2(c2);
  double _n1 = c1.norm();
  double _n2 = c2.norm();

  for (unsigned int i = 0; i < m_approx; i++) {
    double t = std::numbers::pi / m_approx * i;
    _c.set_rep(
        (c1.get_rep()[0] / _n1 * cos(t)) + (c2.get_rep()[0] / _n2 * sin(t)),
        (c1.get_rep()[1] / _n1 * cos(t)) + (c2.get_rep()[1] / _n2 * sin(t)),
        (c1.get_rep()[2] / _n1 * cos(t)) + (c2.get_rep()[2] / _n2 * sin(t)),
        (c1.get_rep()[3] / _n1 * cos(t)) + (c2.get_rep()[3] / _n2 * sin(t)),
        (c1.get_rep()[4] / _n1 * cos(t)) + (c2.get_rep()[4] / _n2 * sin(t)),
        (c1.get_rep()[5] / _n1 * cos(t)) + c2.get_rep()[5] / _n2 * sin(t));
    m_conics.push_back(new Conic(_c));

    m_conics[i]->setColor(255, 215, 0);
  }
}

std::vector<Conic *> Beam::get_conics() { return m_conics; }