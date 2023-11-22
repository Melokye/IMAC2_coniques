// Copyright (c) 2018 by University Paris-Est Marne-la-Vallee
// Directory.cpp
// This file is part of the Garamon Generator.
// Authors: Stephane Breuils and Vincent Nozick
// Contact: vincent.nozick@u-pem.fr
//
// Licence MIT
// A a copy of the MIT License is given along with this program

#include "Directory.hpp"
#include "Geogebra_object.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex> // for substitute
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h> // required for stat.h

#if defined(_WIN32) && defined(__MINGW32__)
#include <direct.h>
#include <io.h>
#endif // __WINDOWS Mingw compiler__

void make_directory(const std::string &dirName) {

  int nError = 0;

#if defined(_WIN32)
  nError = _mkdir(dirName.c_str()); // can be used on Windows
#else
  mode_t nMode = 0733;                    // UNIX style permissions
  nError = mkdir(dirName.c_str(), nMode); // can be used on non-Windows
#endif

  // handle your error here
  if (nError != 0) {
    std::cerr << "error: can not create directory: " << dirName << std::endl;
    exit(EXIT_FAILURE);
  }
}

bool directory_exists(const std::string &dirName) {

  struct stat info;

  if (stat(dirName.c_str(), &info) != 0)
    return false; // cannot access to the directory

  if (info.st_mode & S_IFDIR) // in case of problem, check with: S_ISDIR()
    return true;

  return false; // file exists but is not a directory
}

bool directory_or_file_exists(const std::string &dirName) {

  struct stat info;

  if (stat(dirName.c_str(), &info) == 0)
    return true; // can access to the directory or file

  return false;
}

bool directory_or_file_exists_ifstream(const std::string &name) {
  std::ifstream f(name.c_str());
  return f.good();
}

std::string read_file(const std::string &fileName) {

  std::ifstream myfile;
  myfile.open(fileName, std::ios::in);

  // check if the file is opened
  if (!myfile.is_open()) {
    std::cerr << "error: can not open file: " << fileName << std::endl;
    exit(EXIT_FAILURE);
  }

  // copy the data to a string
  std::string data;
  data.assign((std::istreambuf_iterator<char>(myfile)),
              (std::istreambuf_iterator<char>()));

  myfile.close();

  return data;
}

bool write_file(const std::string &data, const std::string &fileName) {

  std::ofstream myfile(fileName);
  if (!myfile.is_open()) {
    std::cerr << "error: can not create file: " << fileName << std::endl;
    return false;
  }

  myfile << data;
  myfile.close();

  return true;
}

void substitute(std::string &data, const std::string &pattern,
                const std::string &replaceBy) {

  data = std::regex_replace(data, std::regex(pattern), replaceBy);
}

bool copy_bin(const std::string &src, const std::string &dest) {

  std::ifstream srcFile(src, std::ios::binary);
  std::ofstream destFile(dest, std::ios::binary);
  destFile << srcFile.rdbuf();

  return srcFile && destFile;
}

bool copy_text(const std::string &src, const std::string &dest) {

  std::ifstream srcFile(src);
  std::ofstream destFile(dest);
  destFile << srcFile.rdbuf();

  return srcFile && destFile;
}

// TODO à mettre dans le .h ----------------

bool create_input_directory() {
  if (directory_exists("input")) {
    return false;
  } else {
    make_directory("input");
    return true;
  }
}

unsigned int len_file() {
  unsigned int cmpt = 0;
  while (!directory_or_file_exists("input/file_" + std::to_string(cmpt) +
                                   ".txt")) {
    cmpt++;
  }
  return cmpt;
}

/// @brief convert the string format "x y z" into a point
Geogebra_object
string_to_point(const std::string &data) { // TODO à déplacer dans Point.cpp
  Geogebra_object point;                   // TODO mettre un point à la place ?
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