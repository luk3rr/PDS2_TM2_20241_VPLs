/*
 * Filename: pokemon_explosive.h
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef POKEMON_EXPLOSIVE_H_
#define POKEMON_EXPLOSIVE_H_

#include "pokemon.h"

class ExplosivePokemon : public Pokemon
{
    private:
        double m_explosivePower;

    public:
        ExplosivePokemon(std::string name,
                       std::string attackType,
                       double      explosivePower,
                       double      attackStrength);

        virtual ~ExplosivePokemon();

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

#endif // POKEMON_EXPLOSIVE_H_
