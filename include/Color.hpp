#ifndef __COLOR_HPP__
#define __COLOR_HPP__

class Color{
private:
    unsigned int m_r, m_g, m_b;
    
public:
    Color(const unsigned int &r, const unsigned int &g, const unsigned int &b)
    : m_r(r), m_g(g), m_b(b) {}

    ~Color();
};



#endif