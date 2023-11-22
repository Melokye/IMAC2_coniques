
#include "Beam.hpp"

Beam::Beam(Conic c1, Conic c2) {
  for (int i = 0; i < m_approx; i++) {
    double t = 3.141592 / m_approx * i; // pas
    // chacune des i coniques du faisceau vaut : cos(t)*Ca+sin(t)*Cb
    // avec t = pi/i, i dans [0,pi]
    Conic C1(c1); //* std::cos(t);
    C1.set_rep(c1.get_rep()[0], c1.get_rep()[1], c1.get_rep()[2],
               c1.get_rep()[3], c1.get_rep()[4], c1.get_rep()[5]);
    /*
    Conic C2 = newCb * std::sin(t);
    Conic Cc = C1 + C2;
    set_Ci(i, Cc);
    */
  }
}