/*
 * Filename: main.cc
 * Created on: April 27, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "platoon.h"
#include "point.h"
#include "vehicle.h"
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>

int main()
{
    std::size_t totalEvents;   // Número de eventos que ocorrerão
    std::size_t totalVehicles; // Número de veículos que compõem o pelotão
    double_t    maxSpeed;      // Velocidade máxima que os veículos podem atingir
    double_t    targetX;       // Coordenada X do ponto de destino
    double_t    targetY; // Coordenada Y do ponto de destino (não é utilizada, mas é
                         // lida para manter a compatibilidade com o enunciado)

    std::cin >> totalVehicles >> totalEvents >> maxSpeed >> targetX >> targetY;

    Platoon platoon(Point(targetX, targetY), maxSpeed);

    // Adiciona os veículos ao pelotão
    for (std::size_t i = 0; i < totalVehicles; i++)
    {
        double_t start_x, start_y;
        std::cin >> start_x >> start_y;

        platoon.AddVehicle(start_x, start_y);
    }

    // Adiciona os eventos
    for (std::size_t i = 0; i < totalEvents; i++)
    {
        std::size_t simulationTime;
        double_t    acceleration;

        std::cin >> simulationTime >> acceleration;

        platoon.AddEvent(simulationTime, acceleration);
    }

    // Inicia a simulação
    platoon.Start();

    // Imprime os resultados
    std::vector<Vehicle> platoonVehicles = platoon.GetVehicles();
    std::size_t          simulationSteps = platoon.GetSimulationSteps();

    std::cout << simulationSteps << std::endl;

    for (std::size_t i = 0; i < platoonVehicles.size(); i++)
    {
        std::cout << i << " : " << platoonVehicles[i].GetSpeed() << " : "
                  << platoonVehicles[i].GetX() << " " << platoonVehicles[i].GetY()
                  << std::endl;
    }

    return EXIT_SUCCESS;
}
