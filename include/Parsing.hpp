#pragma once

#include "Directory.hpp"
#include "Geogebra_object.hpp"
#include <string>
#include <vector>

// ---
#include "Conic.hpp"
#include "Point.hpp"

// TODO mettre en private ?
std::vector<std::string> split(const std::string &data,
                               const std::string &delimiter);

std::vector<double> string_to_coord(const std::string &data);

// TODO public
Conic extract_data(const std::string &filename);
