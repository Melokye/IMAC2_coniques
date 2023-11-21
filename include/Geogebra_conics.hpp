#ifndef __GEOGEBRA_CONICS_HPP__
#define __GEOGEBRA_CONICS_HPP__

#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>

#include <Eigen/Dense>

#include "Entry.hpp"
#include "Directory.hpp"

#include "Geogebra_object.hpp"
class Viewer_conic
{
public:
    // list of entries
    std::list<Entry> entries;
    bool m_show_axis = true;                              // true to display the axis
    bool m_show_grid = false;                             // true to display a grid
    bool m_show_value = false;                            // true to display the value of each object near the object
    bool m_show_label = false;                            // true to display the value of each object near the object
    bool m_show_xOy_plane = false;                        // show the gray xOy plane
    bool m_oriented_line = false;                         // true to add an arrow on a line to show its direction
    std::vector<float> m_background_color = {1., 1., 1.}; // color of the background (RGB, from 0 to 255 per component)

public:
    Viewer_conic();

    ~Viewer_conic();

    void display() const;

    void removeNameDoublons();

    void render(const std::string &filename);

    /// \brief setter to enable / disable the option to show axis
    inline void show_axis(const bool show_axis_on) { m_show_axis = show_axis_on; }

    /// \brief setter to enable / disable the option to show a grid
    inline void show_grid(const bool show_grid_on) { m_show_grid = show_grid_on; }

    /// \brief setter to enable / disable the option to show the value of each object
    inline void show_value(const bool show_value_on) { m_show_value = show_value_on; }

    /// \brief setter to enable / disable the option to show the label of each object
    inline void show_label(const bool show_label_on) { m_show_label = show_label_on; }

    /// \brief setter to enable / disable the option to show the xOy plane
    inline void show_xOy_plane(const bool m_show_xOy_plane_on) { m_show_xOy_plane = m_show_xOy_plane_on; }

    /// \brief setter to enable / disable the option to show an arrow that specifies the line orientation
    inline void set_oriented_line(const bool oriented_line_on) { m_oriented_line = oriented_line_on; }

    /// \brief setter to choose the color of the background (default is white)
    inline void set_background_color(const unsigned char R, const unsigned char G, const unsigned char B)
    {
        m_background_color = {R / 255.f, G / 255.f, B / 255.f};
    }

    int push_point(const Geogebra_object &p);

    inline int push_line(const Eigen::VectorXd &pt, const Eigen::VectorXd &dir, const unsigned int &red = -1, const unsigned int &green = -1, const unsigned int &blue = -1)
    {
        return push_line(pt, dir, "", red, green, blue);
    }

    int push_line(const Eigen::VectorXd &pt, const Eigen::VectorXd &dir, std::string objectName = "", const unsigned int &red = -1, const unsigned int &green = -1, const unsigned int &blue = -1);

    inline int push_direction(const Eigen::VectorXd &direction, const unsigned int &red = -1, const unsigned int &green = -1, const unsigned int &blue = -1)
    {
        return push_direction(direction, "", red, green, blue);
    }

    int push_direction(const Eigen::VectorXd &direction, std::string objectName = "", const unsigned int &red = -1, const unsigned int &green = -1, const unsigned int &blue = -1);

    inline int push_conic(const Eigen::VectorXd &c, const unsigned int &red = -1, const unsigned int &green = -1, const unsigned int &blue = -1)
    {
        return push_conic(c, "", red, green, blue);
    }

    int push_conic(const Eigen::VectorXd &c, std::string objectName = "", const unsigned int &red = -1, const unsigned int &green = -1, const unsigned int &blue = -1);

    int push(const Geogebra_object &data);
};

#endif