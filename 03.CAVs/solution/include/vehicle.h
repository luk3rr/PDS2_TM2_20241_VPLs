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
        Vehicle(std::size_t id, double_t x, double_t y, double_t maxSpeed);

        std::size_t GetID() const;

        double_t GetSpeed() const;

        double_t GetLimitSpeed() const;

        double_t GetAcceleration() const;

        void SetSpeed(double_t speed);

        void SetAcceleration(double_t acceleration);

        void Move();
};

#endif // VEHICLE_H_
