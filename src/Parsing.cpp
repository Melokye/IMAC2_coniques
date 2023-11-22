#include "Parsing.hpp"
#include "Directory.hpp"
#include "Geogebra_object.hpp"
#include <string>
#include <vector>

// TODO à mettre dans le .h ----------------

std::vector<std::string> split(const std::string &data,
                               const std::string &delimiter) {
  std::vector<std::string> result;
  std::string copy = data;
  unsigned int begin = 0;

  // TODO : à debug
  while (begin < data.length()) {
    unsigned int end = copy.find(delimiter);
    if (end == data.npos)
      end = data.length();

    std::string extracted = data.substr(begin, end);
    result.push_back(extracted);
    std::cout << "extracted : " + extracted << std::endl; // TODO : debug

    begin = end + 1;
    copy = data.substr(begin, data.size());
  }
  return result;
}

/// @brief convert the string format "x y z" into a point
Geogebra_object
string_to_point(const std::string &data) { // TODO à déplacer dans Point.cpp
  Geogebra_object point; // TODO specifier un point à la place ?
  // TODO à finir

  return point;
}

// TODO liste de conique
/// @brief extract the data to create a conic
Geogebra_object extract_data(const std::string &filename) {
  std::string data = read_file(filename);
  std::string delimiter = " ";
  unsigned int begin = 0;
  Geogebra_object conic; // TODO c'est une variadique ...
  while (data.find(delimiter) != data.npos) {
    unsigned int end = data.find("\n");
    std::string extracted = data.substr(begin, end);
    Geogebra_object point = string_to_point(extracted);
    // TODO add to conic
    begin = end;
    data = data.substr(begin, data.size());
  }

  // Conic(Point{1, 2}, Point{2., 2}, Point{3., 2}, Point{4, 1.},
  // Point{5., 1.});
}

// TODO substitute : data -> file