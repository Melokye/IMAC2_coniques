/**
 * @file main.cpp
 * @author Tanya FRANCOIS et Mélodie KOUY
 * @brief generate two conic from point and beam of these two conic
 * 
 * @copyright Copyright (c) 2023
 * 
 */

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

  // CONIQUE cercle
  Conic cercle = Conic(Point{1, 0}, Point{sqrt(3) / 2., 1 / 2.},
                  Point{sqrt(2) / 2., sqrt(2) / 2.},
                  Point{-sqrt(3) / 2., 1 / 2.}, Point{0, 1}, Point{1, 2});

  Conic parallele;

  if(!create_directory("../input")){
    parallele = extract_data("../input/file_0.txt");
  }else{
    std::cout << "fichier non ouvert..." << std::endl;

    // CONIQUE droite parallèle
    parallele = Conic(Point{1, 2}, Point{2., 2}, Point{3., 2}, Point{4, 1.},
                   Point{5., 1.});
  }

  Beam b(cercle, parallele);
  std::vector<Conic *> conics = b.get_conics();
  std::vector<Geogebra_object *> geo_obj;

  for (Point el : p)
    geo_obj.push_back(new Point(el));

  for (Conic *el : conics)
    geo_obj.push_back(new Conic(*el));

  geo_obj.push_back(new Conic(cercle));
  geo_obj.push_back(new Conic(parallele));

  Viewer v(geo_obj);

  v.display();

  // std::cout << "Type conique : " << c.conicType() << std::endl;

  return 0;
}
