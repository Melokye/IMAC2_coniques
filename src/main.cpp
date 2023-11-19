#include <Eigen/Dense>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "Conic.hpp"
#include "Geogebra_conics.hpp"

int main() {
  // the viewer will open a file whose path is writen in hard (bad!!).
  // So you should either launch your program from the fine directory or change
  // the path to this file.

  std::vector<Point> p = {Point{1, 0},
                          Point{sqrt(3) / 2., 1 / 2.},
                          Point{sqrt(2) / 2., sqrt(2) / 2.},
                          Point{-sqrt(3) / 2., 1 / 2.},
                          Point{0, 1},
                          Point{1, 2}};

  Conic c = Conic(Point{1, 0}, Point{sqrt(3) / 2., 1 / 2.},
                  Point{sqrt(2) / 2., sqrt(2) / 2.},
                  Point{-sqrt(3) / 2., 1 / 2.}, Point{0, 1}, Point{1, 2});

  Viewer_conic viewer;

  // viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);

  for (unsigned int i = 0; i < p.size(); i++) {
    std::string name = "p " + std::to_string(i + 1);
    viewer.push_point(
        (Eigen::VectorXd(3) << p[i].getX(), p[i].getY(), p[i].getW())
            .finished(),
        name, 200, 0, 0);
  }

  Eigen::VectorXd conic(6);
  conic << c.getCoeff(); // coeff conique - ellipse
  viewer.push_conic(conic, 100, 0, 200);

  // render
  viewer.display();                    // on terminal
  viewer.render("output/output.html"); // generate the output file (to open with
                                       // your web browser)

  std::cout << "Type conique : " << c.conicType() << std::endl;

  return 0;
}
