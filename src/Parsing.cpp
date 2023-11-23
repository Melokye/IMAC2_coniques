#include "Parsing.hpp"
#include "Directory.hpp"
#include "Geogebra_object.hpp"
#include <string>
#include <vector>

// TODO à mettre dans le .h ----------------

std::vector<std::string> split(const std::string &data,
                               const std::string &delimiter) {
  std::vector<std::string> result;
  std::size_t begin = 0;
  std::size_t end = 0;

  while (end != data.length()) {
    end = data.find(delimiter, begin);
    if (end == data.npos)
      end = data.length();
    
    std::string extracted = data.substr(begin, end - begin);
    result.push_back(extracted);
    begin = end + 1;
  }
  return result;
}

/// @brief convert the string format "x y z" into list of coord
std::vector<double> string_to_coord(const std::string &data) {
  std::vector<double> coord;
  // TODO à tester
  for(std::string c : split(data, " "))
     coord.push_back(stod(c));
  return coord;
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
    std::vector convert = string_to_coord(extracted);
    // TODO add to conic
    begin = end;
    data = data.substr(begin, data.size());
  }

  // Conic(Point{1, 2}, Point{2., 2}, Point{3., 2}, Point{4, 1.},
  // Point{5., 1.});
  // TODO return
}

// TODO substitute : data -> file