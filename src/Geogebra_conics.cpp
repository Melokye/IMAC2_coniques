#include <iostream>

#include "Entry.hpp"
#include "Geogebra_conics.hpp"

Viewer_conic::Viewer_conic() {}

Viewer_conic::~Viewer_conic() {}

void Viewer_conic::display() const
{
    for (const auto &e : entries)
        e.display();
}

void Viewer_conic::removeNameDoublons()
{

    // for each entry, find if there is multiple occurences of the same name
    auto e = entries.begin();
    while (e != entries.end())
    {

        // check all the remaining entries
        int count = 2;
        auto e2 = e;
        ++e2;
        while (e2 != entries.end())
        {
            if ((*e)._objectName == (*e2)._objectName)
            {
                (*e2)._objectName += std::to_string(count);
                ++count;
            }
            ++e2;
        }
        ++e;
    }
}

void Viewer_conic::render(const std::string &filename)
{

    // open the template file
    std::string data = readFile("../data/geogebra_conics_template.html");

    // remove name doublons
    removeNameDoublons();

    // build output commands
    std::string commands = "";

    // options
    if (m_show_axis)
        commands += "   api.evalCommand(\"ShowAxes(true)\");\n";
    else
        commands += "   api.evalCommand(\"ShowAxes(false)\");\n";

    if (m_show_grid)
        commands += "   api.evalCommand(\"ShowGrid(true)\");\n";
    else
        commands += "   api.evalCommand(\"ShowGrid(false)\");\n";

    commands += "   api.evalCommand(\"CenterView((0, 0))\");\n";

    // https://wiki.geogebra.org/en/SetBackgroundColor_Command
    commands += "   api.evalCommand(\"SetBackgroundColor(" 
                + std::to_string(m_background_color[0]) + "," 
                + std::to_string(m_background_color[1]) + "," 
                + std::to_string(m_background_color[2]) 
                + ")\");\n";

    // for each entry, extract the command
    for (const auto &e : entries)
    {

        // equation
        commands += "   api.evalCommand(\"";
        commands += (e._objectName == "") ? "" : e._objectName + " : ";
        commands += e.m_equation + "\");\n";

        // color
        if (e.m_color[0] != -1)
            commands += "   api.evalCommand(\"SetColor(" 
                        + e._objectName + ", " 
                        + std::to_string(e.m_color[0] / 255.0) + ", " 
                        + std::to_string(e.m_color[1] / 255.0) + ", " 
                        + std::to_string(e.m_color[2] / 255.0) 
                        + ")\");\n";

        // show labels and values
        // show value (0=Name, 1=Name + Value, 2=Value)
        if ((e.m_show_label == true) && (e.m_show_value == true))
        {
            commands += "   api.evalCommand(\"ShowLabel(" + e._objectName + ", true)\");\n";
            commands += "   api.evalCommand(\"SetLabelMode(" + e._objectName + ", 1)\");\n";
        }
        if ((e.m_show_label == true) && (e.m_show_value == false))
        {
            commands += "   api.evalCommand(\"ShowLabel(" + e._objectName + ", true)\");\n";
            commands += "   api.evalCommand(\"SetLabelMode(" + e._objectName + ", 0)\");\n";
        }
        if ((e.m_show_label == false) && (e.m_show_value == true))
        {
            commands += "   api.evalCommand(\"ShowLabel(" + e._objectName + ", true)\");\n";
            commands += "   api.evalCommand(\"SetLabelMode(" + e._objectName + ", 2)\");\n";
        }
        if ((e.m_show_label == false) && (e.m_show_value == false))
        {
            commands += "   api.evalCommand(\"ShowLabel(" + e._objectName + ", false)\");\n";
        }
    }

    // substitute command on template file
    substitute(data, "__GARAMON_INSTER_DATA_FLAG__", commands);

    // save file
    writeFile(data, filename);
}

// https://wiki.geogebra.org/en/Point_Command
int Viewer_conic::push(const Geogebra_object &p){
    // push the entry
    entries.push_back(Entry(p.equation(), p.name(), 
        p.color().r(), p.color().g(), p.color().b(), 
        m_show_label, m_show_value));

    // finish
    return EXIT_SUCCESS;
}

// https://wiki.geogebra.org/en/Line_Command
int Viewer_conic::push_line(
    const Eigen::VectorXd &pt, const Eigen::VectorXd &dir, std::string objectName,
    const unsigned int &red, const unsigned int &green, const unsigned int &blue)
{
    // remove space in the name // TODO à eff
    objectName.erase(std::remove(objectName.begin(), objectName.end(), ' '), objectName.end());

    // final equation
    std::string equation;

    equation = " Line((" + std::to_string(pt[0]) + "," + std::to_string(pt[1]) 
                + "), Vector((" + std::to_string(dir[0]) + "," + std::to_string(dir[1]) + ")))";

    // put a default name
    if (objectName == "")
        objectName = "l";

    // push the entry
    entries.push_back(Entry(equation, objectName, red, green, blue, 
                            m_show_label, m_show_value));

    // finish
    return EXIT_SUCCESS;
}

// https://wiki.geogebra.org/en/Line_Command
int Viewer_conic::push_direction(const Eigen::VectorXd &direction, std::string objectName,
    const unsigned int &red, const unsigned int &green, const unsigned int &blue)
{
    // remove space in the name // TODO à eff
    objectName.erase(std::remove(objectName.begin(), objectName.end(), ' '),
                     objectName.end());

    // final equation
    std::string equation;

    equation = " Line((0.0,0.0,0.0), Vector((" + std::to_string(direction[0]) +
               "," + std::to_string(direction[1]) + ")))";

    // put a default name
    if (objectName == "")
        objectName = "l";

    // push the entry
    entries.push_back(Entry(equation, objectName, red, green, blue, m_show_label,
                            m_show_value));

    // finish
    return EXIT_SUCCESS;
}

// https://wiki.geogebra.org/en/Conic_Command // TODO à déplacer