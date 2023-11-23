
#include "Parsing.hpp"

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

/// @brief convert the string format "x y z ..." into list of coord
std::vector<double> string_to_coord(const std::string &data) {
  std::vector<double> coord;
  for (std::string c : split(data, " "))
    coord.push_back(stod(c));
  return coord;
}

// TODO à mettre dans le .h ----------------

// TODO liste de conique
/// @brief extract the data to create a conic
Conic extract_data(const std::string &filename) {
  // TODO check si filename existe ?
  std::string file_content = read_file(filename);
  std::vector<std::string> data = split(file_content, std::string("\n"));
  std::vector<Point> points;

  // create points
  for (std::string convert : data) {
    std::vector<double> coord = string_to_coord(convert);
    points.push_back(
        Point(coord.at(0), coord.at(1), coord.at(2))); // TODO peut mieux faire
  }

  // create conic
  Conic conic;
  if (points.size() >= 5) {
    conic = Conic(points.at(0), points.at(1), points.at(2), points.at(3),
                  points.at(4));

    for (size_t i = 5; i < points.size(); i++)
      conic.add_point(points.at(i));
  }
  // TODO else pb ?
  return conic;
}

// TODO substitute : data -> file