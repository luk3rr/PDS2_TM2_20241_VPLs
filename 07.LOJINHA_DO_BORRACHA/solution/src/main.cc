/*
 * Filename: main.cc
 * Created on: April 30, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <cstdlib>
#include <iostream>

#include "rinha.h"
#include "trainer.h"

int main()
{
    Rinha       rinha;
    char        command;
    std::string trainerName, pokemonName;
    std::string trainerName1, pokemonName1, trainerName2, pokemonName2;
    double      attackStrength, attackPower;

    bool keepRunning = true;

    while (std::cin >> command and keepRunning)
    {
        switch (command)
        {
            case 't':
                std::cin >> trainerName;
                rinha.AddTrainer(trainerName);
                break;

            case 'i':
                std::cin >> trainerName;
                rinha.GetTrainer(trainerName)->PrintInfo();
                break;

            case 'e':
                std::cin >> trainerName >> pokemonName >> attackPower >> attackStrength;

                rinha.AddElectricPokemon(trainerName,
                                         pokemonName,
                                         attackPower,
                                         attackStrength);

                break;

            case 'a':
                std::cin >> trainerName >> pokemonName >> attackPower >> attackStrength;

                rinha.AddAquaticPokemon(trainerName,
                                        pokemonName,
                                        attackPower,
                                        attackStrength);
                break;

            case 'x':
                std::cin >> trainerName >> pokemonName >> attackPower >> attackStrength;

                rinha.AddExplosivePokemon(trainerName,
                                          pokemonName,
                                          attackPower,
                                          attackStrength);
                break;

            case 'r':
                std::cin >> trainerName1 >> pokemonName1 >> trainerName2 >>
                    pokemonName2;

                rinha.Fight(trainerName1, pokemonName1, trainerName2, pokemonName2);
                break;

            default:
                keepRunning = false;
                break;
        }
    }

    std::cout << "Fim da execução" << std::endl;
    return EXIT_SUCCESS;
}
