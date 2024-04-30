/*
 * Filename: platoon.cc
 * Created on: April 30, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "platoon.h"

Platoon::Platoon(Point target, double maxSpeed)
    : m_target(target)
{
    m_maxSpeed        = maxSpeed;
    m_simulationSteps = 0;
}

std::vector<Vehicle> Platoon::GetVehicles() const
{
    return m_vehicles;
}

std::size_t Platoon::GetSimulationSteps() const
{
    return m_simulationSteps;
}

void Platoon::AddVehicle(double_t start_x, double_t start_y)
{
    m_vehicles.push_back(
        Vehicle(this->m_vehicles.size(), start_x, start_y, m_maxSpeed));
}

void Platoon::AddEvent(std::size_t simulation_time, double_t acceleration)
{
    m_events.push_back({ simulation_time, acceleration });
}

void Platoon::Start()
{
    if (this->m_events.size() == 0)
    {
        std::cerr << "No course plan was defined" << std::endl;
    }

    this->m_nextEvent = this->m_events[0];
    this->m_events.erase(this->m_events.begin());

    while (this->m_vehicles[0].GetX() < this->m_target.GetX())
    {
        if (this->m_simulationSteps == this->m_nextEvent.m_simulationTime)
        {
            for (std::size_t i = 0; i < this->m_vehicles.size(); i++)
            {
                this->m_vehicles[i].SetAcceleration(this->m_nextEvent.m_acceleration);
            }

            if (this->m_events.size() > 0)
            {
                this->m_nextEvent = this->m_events[0];
                this->m_events.erase(this->m_events.begin());
            }
        }

        for (std::size_t i = 0; i < this->m_vehicles.size(); i++)
        {
            this->m_vehicles[i].Move();
        }

        this->m_simulationSteps++;
    }
}
