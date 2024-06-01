/*
 * Filename: trainer.h
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef TRAINER_H_
#define TRAINER_H_

#include <iostream>
#include <string>
#include <vector>

#include "pokemon.h"
#include "rinhaExcept.h"
#include "pokemon_aquatic.h"
#include "pokemon_electric.h"
#include "pokemon_explosive.h"

class Trainer
{
    private:
        std::string           m_name;
        std::vector<Pokemon*> m_pokemons;

        bool FindPokemon(std::string name);

    public:
        Trainer(std::string name);
        ~Trainer();

        /**
         * @brief Add a new Aquatic Pokemon
         * @param name The name of the Pokemon
         * @param attackType The type of the attack
         * @param aquaticPower The aquatic power of the Pokemon
         * @param attackStrength The attack strength of the Pokemon
         **/
        void AddAquaticPokemon(std::string name,
                               std::string attackType,
                               double      aquaticPower,
                               double      attackStrength);

        /**
         * @brief Add a new Electric Pokemon
         * @param name The name of the Pokemon
         * @param attackType The type of the attack
         * @param electricPower The electric power of the Pokemon
         * @param attackStrength The attack strength of the Pokemon
         **/
        void AddElectricPokemon(std::string name,
                                std::string attackType,
                                double      electricPower,
                                double      attackStrength);

        /**
         * @brief Add a new Explosive Pokemon
         * @param name The name of the Pokemon
         * @param attackType The type of the attack
         * @param explosivePower The explosive power of the Pokemon
         * @param attackStrength The attack strength of the Pokemon
         **/
        void AddExplosivePokemon(std::string name,
                                 std::string attackType,
                                 double      explosivePower,
                                 double      attackStrength);

        /**
         * @brief Get the name of the Trainer
         * @return The name of the Trainer
         **/
        std::string GetName();

        /**
         * @brief Find a Pokemon by its name
         * @param name The name of the Pokemon
         * @return A pointer to the Pokemon if it is found, nullptr otherwise
         **/
        Pokemon* UsePokemon(std::string name);

        /**
         * @brief Print the information of the Trainer
         **/
        void PrintInfo();
};

#endif // TRAINER_H_
