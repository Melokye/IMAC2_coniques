#include "Viewer.hpp"

Viewer::Viewer(const std::vector<Geogebra_object *> &geo_obj) {
  m_viewer.set_background_color(250, 250, 255);
  m_viewer.show_axis(true);
  m_viewer.show_grid(false);
  m_viewer.show_value(false);
  m_viewer.show_label(true);

  /* ------------ ajout ------------ */

  for (unsigned int i = 0; i < geo_obj.size(); i++)
    geo_obj[i]->push(m_viewer);

  std::cout << "AFFICHAGE..." << std::endl;
  m_viewer.display(); // on terminal
  m_viewer.render("output/output.html");
}
