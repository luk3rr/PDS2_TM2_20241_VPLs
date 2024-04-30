/*
 * Filename: vehicle.h
 * Created on: April 27, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "point.h"
#include <cmath>
#include <iostream>

class Vehicle : public Point
{
    private:
        std::size_t m_id;
        double_t    m_speed;
        double_t    m_maxSpeed;
        double_t    m_acceleration;

    public:
        Vehicle(std::size_t id, double_t x, double_t y, double_t limitSpeed)
            : Point(x, y)
        {
            this->m_id           = id;
            this->m_maxSpeed     = limitSpeed;
            this->m_speed        = 0;
            this->m_acceleration = 0;
        }

        std::size_t GetID() const
        {
            return this->m_id;
        }

        double_t GetSpeed() const
        {
            return this->m_speed;
        }

        double_t GetLimitSpeed() const
        {
            return this->m_maxSpeed;
        }

        double_t GetAcceleration() const
        {
            return this->m_acceleration;
        }

        void SetSpeed(double_t speed)
        {
            this->m_speed = speed;
        }

        void SetAcceleration(double_t acceleration)
        {
            this->m_acceleration = acceleration;
        }

        void Move()
        {
            this->m_speed += this->m_acceleration;

            if (this->m_speed > m_maxSpeed)
                this->m_speed = m_maxSpeed;

            double newX = this->GetX() + m_speed;
            this->SetX(newX);
        }
};

#endif // VEHICLE_H_
