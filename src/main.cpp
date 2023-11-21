#include <Eigen/Dense>
#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "Conic.hpp"
#include "Geogebra_conics.hpp"
#include "Color.hpp"

int main()
{
  // the viewer will open a file whose path is writen in hard (bad!!).
  // So you should either launch your program from the fine directory or change
  // the path to this file.

  Point p1(2, 4);
  // std::vector<Point> p = {{3, 5}, {1, 2}, {0, 4}, {6, 6}, {2, 8}};
    // exemple marrant

  std::vector<Point> points = {
      {0, -2}, {2, 0}, {sqrt(3) / 2., 1 / 2.}, {-2, 0}, {0, 2}};
  Conic c = Conic(points);

  Viewer_conic viewer;

  // viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);

  for (Point p : points){ // TODO surcharge ?
    viewer.push(p);
  }

  viewer.push(c); // TODO 

  // render
  viewer.display();                    // on terminal
  viewer.render("output/output.html"); // generate the output file (to open with your
                                       // web browser)

  std::cout << "Type conique : " << c.conicType() << std::endl;

  return 0;
}
