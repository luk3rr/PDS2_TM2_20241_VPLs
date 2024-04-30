/*
 * Filename: vehicle.cc
 * Created on: April 30, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "vehicle.h"

Vehicle::Vehicle(std::size_t id, double_t x, double_t y, double_t maxSpeed)
    : Point(x, y)
{
    this->m_id           = id;
    this->m_maxSpeed     = maxSpeed;
    this->m_speed        = 0;
    this->m_acceleration = 0;
}

std::size_t Vehicle::GetID() const
{
    return this->m_id;
}

double_t Vehicle::GetSpeed() const
{
    return this->m_speed;
}

double_t Vehicle::GetLimitSpeed() const
{
    return this->m_maxSpeed;
}

double_t Vehicle::GetAcceleration() const
{
    return this->m_acceleration;
}

void Vehicle::SetSpeed(double_t speed)
{
    this->m_speed = speed;
}

void Vehicle::SetAcceleration(double_t acceleration)
{
    this->m_acceleration = acceleration;
}

void Vehicle::Move()
{
    this->m_speed += this->m_acceleration;

    if (this->m_speed > m_maxSpeed)
        this->m_speed = m_maxSpeed;

    double newX = this->GetX() + m_speed;
    this->SetX(newX);
}
