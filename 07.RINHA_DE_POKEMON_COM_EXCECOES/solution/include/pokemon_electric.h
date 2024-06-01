/*
 * Filename: pokemon_electric.h
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef POKEMON_ELECTRIC_H_
#define POKEMON_ELECTRIC_H_

#include <string>
#include <iostream>

#include "pokemon.h"

class ElectricPokemon : public Pokemon
{
    private:
        double m_electricPower;

    public:
        ElectricPokemon(std::string name,
                        std::string attackType,
                        double      electricPower,
                        double      attackStrength);

        virtual ~ElectricPokemon();

        /**
         * @brief Calculates the damage of an attack
         * @return The damage of the attack
         **/
        virtual double CalculateDamage() override;

        /**
         * @brief Prints the attack type of the Pokemon
         **/
        void SayAttackType() const override;
};

#endif // POKEMON_ELECTRIC_H_
