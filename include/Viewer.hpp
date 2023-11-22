#pragma once
#include "Geogebra_conics.hpp"
#include "Geogebra_object.hpp"
#include "Point.hpp"
#include <vector>

class Viewer {
private:
  Viewer_conic m_viewer;

public:
  Viewer(const std::vector<Geogebra_object *> &geo_obj);
  ~Viewer(){};
};
