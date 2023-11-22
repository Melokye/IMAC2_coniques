#include "Viewer.hpp"

Viewer::Viewer(const std::vector<Geogebra_object *> &geo_obj) {
  m_viewer.set_background_color(250, 250, 255);
  m_viewer.show_axis(true);
  m_viewer.show_grid(false);
  m_viewer.show_value(false);
  m_viewer.show_label(true);

  /* ------------ ajout ------------ */
  std::for_each(geo_obj.begin(), geo_obj.end(),
                [this](auto obj) { obj->push(m_viewer); });
}

void Viewer::add_obj(const Geogebra_object *obj) { obj->push(m_viewer); }

void Viewer::display() {
  std::cout << "\n\n/* --------------- AFFICHAGE --------------- */\n\n"
            << std::endl;
  m_viewer.display(); // on terminal
  m_viewer.render("output/output.html");
}