/*
 * Filename: pokemon_aquatic.h
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef POKEMON_AQUATIC_H_
#define POKEMON_AQUATIC_H_

#include <iostream>

#include "pokemon.h"

class AquaticPokemon : public Pokemon
{
    private:
        double m_aquaticPower;

    public:
        AquaticPokemon(std::string name,
                       std::string attackType,
                       double      aquaticPower,
                       double      attackStrength);

        virtual ~AquaticPokemon();

        /**
         * @brief Calculates the damage of the attack
         * @return The damage of the attack
         **/
        virtual double CalculateDamage() override;

        /**
         * @brief Prints the attack type of the Pokemon
         **/
        void SayAttackType() const override;
};

#endif // POKEMON_AQUATIC_H_
