/*
 * Filename: point.h
 * Created on: April 27, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef POINT_H_
#define POINT_H_

#include <cmath>

class Point
{
    private:
        double_t m_x, m_y;

    public:
        Point(double_t x, double_t y)
        {
            m_x = x;
            m_y = y;
        }

        void SetX(double_t x)
        {
            m_x = x;
        }

        void SetY(double_t y)
        {
            m_y = y;
        }

        double_t GetX() const
        {
            return m_x;
        }

        double_t GetY() const
        {
            return m_y;
        }
};

#endif // POINT_H_
