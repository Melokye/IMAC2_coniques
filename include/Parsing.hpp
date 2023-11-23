#ifndef __PARSING_HPP__
#define __PARSING_HPP__

#include <string>
#include <vector>

std::vector<std::string> split(const std::string &data,
                               const std::string &delimiter);
                
std::vector<double> string_to_coord(const std::string &data);
#endif