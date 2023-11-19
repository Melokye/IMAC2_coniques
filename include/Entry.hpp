#ifndef __ENTRY_HPP__
#define __ENTRY_HPP__

#include <iostream>
#include <vector>
#include <string>

/// @brief Display on the terminal
class Entry
{
public:
    // object equation or geogebra formulation
    std::string m_equation;

    // object name
    std::string _objectName;

    // color (from 0 to 255)
    std::vector<int> m_color; // TODO ?

    // show label
    bool m_show_label;

    // show value
    bool m_show_value;

public:
    Entry() = default;

    Entry(const std::string &equation,
          const std::string &objectName,
          const int &red = -1,
          const int &green = -1,
          const int &blue = -1,
          bool show_label = false,
          bool show_value = false);

    ~Entry() = default;

    void display() const;
};

#endif