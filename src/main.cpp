#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

int main() {
  // the viewer will open a file whose path is writen in hard (bad!!).
  // So you should either launch your program from the fine directory or change
  // the path to this file.
  Viewer_conic viewer;

  // viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);

  // draw points
  Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(3);
  pt1 << 1.5, 2.0;
  pt2 << 3.0, 1.0;
  pt3 << -2.0, -1.0;
  pt4 << -4.0, -3.0, 0;

  viewer.push_point(pt1, "p1", 200, 0, 0);
  viewer.push_point(pt2, "p2", 200, 0, 0);
  viewer.push_point(pt3, 200, 0, 0);
  viewer.push_point(pt4, "p2", 200, 0, 0);

  // draw line
  viewer.push_line(pt1, pt2 - pt1, 200, 200, 0);

  // draw conic
  Eigen::VectorXd conic(6);
  conic << 1.4, -0.3, -1, -0.6, 0.0, 0.8; // coeff  conique - hyperbole
  viewer.push_conic(conic, 0, 100, 200);

  Eigen::VectorXd conic2(6);
  conic2 << -2.8, -0.6, -2, -1.2, 0.0, 1.6; // coeff conique - ellipse
  viewer.push_conic(conic2, 100, 0, 200);

  // render
  viewer.display();             // on terminal
  viewer.render("output.html"); // generate the output file (to open with your
                                // web browser)

  return 0;
}
