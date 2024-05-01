/*
 * Filename: pokemon_explosive.cc
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "pokemon_explosive.h"
#include <iostream>

ExplosivePokemon::ExplosivePokemon(std::string name,
                                   std::string attackType,
                                   double      explosivePower,
                                   double      attackStrength)
    : Pokemon(name, attackType, attackStrength)
{
    this->m_explosivePower = explosivePower;
}

ExplosivePokemon::~ExplosivePokemon()
{
    std::cout << "Classe derivada : Pokémon explosivo " << this->GetName()
              << " diz: Adeus!" << std::endl;
}

double ExplosivePokemon::CalculateDamage()
{
    return this->m_explosivePower * this->GetAttackStrength();
}

void ExplosivePokemon::SayAttackType() const
{
    std::cout << "Explosivo! Booom!" << std::endl;
}
