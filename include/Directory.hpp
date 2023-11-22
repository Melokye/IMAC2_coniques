// Copyright (c) 2018 by University Paris-Est Marne-la-Vallee
// Directory.hpp
// This file is part of the Garamon Generator.
// Authors: Stephane Breuils and Vincent Nozick
// Contact: vincent.nozick@u-pem.fr
//
// Licence MIT
// A a copy of the MIT License is given along with this program

/// \file Directory.hpp
/// \author Stephane Breuils, Vincent Nozick
/// \brief Basic tools to manipulate files and directories.

#ifndef GA_DIRECTORY_HPP__
#define GA_DIRECTORY_HPP__

#include <string>
#include <vector>

void make_directory(const std::string &dirName);

bool directory_exists(const std::string &dirName);

bool directory_or_file_exists(const std::string &dirName);

bool directory_or_file_exists_ifstream(const std::string &name);

std::string read_file(const std::string &fileName);

bool write_file(const std::string &data, const std::string &fileName);

void substitute(std::string &data, const std::string &pattern,
                const std::string &replaceBy);

bool copy_bin(const std::string &src, const std::string &dest);

bool copy_text(const std::string &src, const std::string &dest);

bool create_input_directory();

unsigned int len_file();

#endif // GA_DIRECTORY_HPP__