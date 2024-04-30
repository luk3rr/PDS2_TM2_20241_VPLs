/*
 * Filename: platoon.h
 * Created on: April 27, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef PLATOON_H_
#define PLATOON_H_

#include <cmath>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

#include "point.h"
#include "vehicle.h"

struct Event
{
        std::size_t m_simulationTime;
        double_t    m_acceleration;
};

class Platoon
{
    private:
        std::vector<Vehicle> m_vehicles;
        std::vector<Event>   m_events;
        Point                m_target;
        double_t             m_maxSpeed;
        std::size_t          m_simulationSteps;
        Event                m_nextEvent;

    public:
        Platoon(Point target, double_t maxSpeed)
            : m_target(target)
        {
            m_maxSpeed = maxSpeed;
            m_simulationSteps = 0;
        }

        std::vector<Vehicle> GetVehicles() const
        {
            return m_vehicles;
        }

        std::size_t GetSimulationSteps() const
        {
            return m_simulationSteps;
        }

        void AddVehicle(double_t start_x, double_t start_y)
        {
            m_vehicles.push_back(
                Vehicle(this->m_vehicles.size(), start_x, start_y, m_maxSpeed));
        }

        void AddEvent(std::size_t simulation_time, double_t acceleration)
        {
            m_events.push_back({ simulation_time, acceleration });
        }

        void Start()
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
                        this->m_vehicles[i].SetAcceleration(
                            this->m_nextEvent.m_acceleration);
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
};

#endif // PLATOON_H_
