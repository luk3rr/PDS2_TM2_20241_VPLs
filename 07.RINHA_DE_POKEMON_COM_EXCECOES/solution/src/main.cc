/*
 * Filename: main.cc
 * Created on: April 30, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

#include "rinha.h"
#include "trainer.h"
#include "rinhaExcpt.h"

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
                try
                {
                    rinha.AddTrainer(trainerName);
                }
                catch (TrainerAlreadyExists &e)
                {
                    std::cout << e.what() << std::endl;
                }
                break;

            case 'i':
                std::cin >> trainerName;

                try
                {
                    rinha.GetTrainer(trainerName)->PrintInfo();
                }
                catch (TrainerNotFound &e)
                {
                    std::cout << e.what() << std::endl;
                }

                break;

            case 'e':
                std::cin >> trainerName >> pokemonName >> attackPower >> attackStrength;

                try
                {
                    rinha.AddElectricPokemon(trainerName,
                                             pokemonName,
                                             attackPower,
                                             attackStrength);
                }
                catch (std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }


                break;

            case 'a':
                std::cin >> trainerName >> pokemonName >> attackPower >> attackStrength;

                try
                {
                    rinha.AddAquaticPokemon(trainerName,
                                            pokemonName,
                                            attackPower,
                                            attackStrength);
                }
                catch (std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }

                break;

            case 'x':
                std::cin >> trainerName >> pokemonName >> attackPower >> attackStrength;

                try
                {
                    rinha.AddExplosivePokemon(trainerName,
                                              pokemonName,
                                              attackPower,
                                              attackStrength);
                }
                catch (std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }

                break;

            case 'r':
                std::cin >> trainerName1 >> pokemonName1 >> trainerName2 >>
                    pokemonName2;

                try
                {
                    rinha.Fight(trainerName1, pokemonName1, trainerName2, pokemonName2);
                }
                catch (std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }

                break;

            default:
                keepRunning = false;
                break;
        }
    }

    std::cout << "Fim da execução" << std::endl;
    return EXIT_SUCCESS;
}
