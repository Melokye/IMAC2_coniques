#include <Eigen/Dense>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "Conic.hpp"
#include "Geogebra_conics.hpp"
#include "Viewer.hpp"

int main() {
  // the viewer will open a file whose path is writen in hard (bad!!).
  // So you should either launch your program from the fine directory or change
  // the path to this file.

  std::vector<Point> p = {Point{1, 2}, Point{2., 2}, Point{3., 2}, Point{4, 1.},
                          Point{5., 1.}};

  Conic c = Conic(Point{1, 0}, Point{sqrt(3) / 2., 1 / 2.},
                  Point{sqrt(2) / 2., sqrt(2) / 2.},
                  Point{-sqrt(3) / 2., 1 / 2.}, Point{0, 1}, Point{1, 2});

  // BONNE CONIQUE
  Conic c2 = Conic(Point{1, 2}, Point{2., 2}, Point{3., 2}, Point{4, 1.},
                   Point{5., 1.});

  std::vector<Geogebra_object *> geo_obj;

  for (Point el : p)
    geo_obj.push_back(new Point(el));

  geo_obj.push_back(new Conic(c));
  geo_obj.push_back(new Conic(c2));

  Viewer v(geo_obj);

  // std::cout << "Type conique : " << c.conicType() << std::endl;

  return 0;
}
