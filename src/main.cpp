#include <Eigen/Dense>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "Beam.hpp"
#include "Conic.hpp"
#include "Geogebra_conics.hpp"
#include "Viewer.hpp"

#include "Parsing.hpp"

int main() {

  std::vector<Point> p = {Point{1, 2}, Point{2., 2}, Point{3., 2}, Point{4, 1.},
                          Point{5., 1.}};

  Conic c = Conic(Point{1, 0}, Point{sqrt(3) / 2., 1 / 2.},
                  Point{sqrt(2) / 2., sqrt(2) / 2.},
                  Point{-sqrt(3) / 2., 1 / 2.}, Point{0, 1}, Point{1, 2});

  // CONIQUE droite parallèle
  // Conic c2 = Conic(Point{1, 2}, Point{2., 2}, Point{3., 2}, Point{4, 1.},
  //                  Point{5., 1.});

  // TODO test fichier
  // TODO test directory aussi
  Conic c2 = extract_data("input/file_0.txt");

  Beam b(c, c2);
  std::vector<Conic *> conics = b.get_conics();
  std::vector<Geogebra_object *> geo_obj;

  for (Point el : p)
    geo_obj.push_back(new Point(el));

  for (Conic *el : conics)
    geo_obj.push_back(new Conic(*el));

  geo_obj.push_back(new Conic(c));
  geo_obj.push_back(new Conic(c2));

  Viewer v(geo_obj);

  v.display();

  // std::cout << "Type conique : " << c.conicType() << std::endl;

  return 0;
}
