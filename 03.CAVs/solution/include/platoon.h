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
        Platoon(Point target, double_t maxSpeed);

        std::vector<Vehicle> GetVehicles() const;

        std::size_t GetSimulationSteps() const;

        void AddVehicle(double_t start_x, double_t start_y);

        void AddEvent(std::size_t simulation_time, double_t acceleration);

        void Start();
};

#endif // PLATOON_H_
