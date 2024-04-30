/*
 * Filename: point.cc
 * Created on: April 30, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "point.h"

Point::Point(double_t x, double_t y)
{
    m_x = x;
    m_y = y;
}

void Point::SetX(double_t x)
{
    m_x = x;
}

void Point::SetY(double_t y)
{
    m_y = y;
}

double_t Point::GetX() const
{
    return m_x;
}

double_t Point::GetY() const
{
    return m_y;
}
