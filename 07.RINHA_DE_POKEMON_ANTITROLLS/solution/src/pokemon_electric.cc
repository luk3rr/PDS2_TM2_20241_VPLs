/*
 * Filename: pokemon_electric.cc
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "pokemon_electric.h"

ElectricPokemon::ElectricPokemon(std::string name,
                                 std::string attackType,
                                 double      electricPower,
                                 double      attackStrength)
    : Pokemon(name, attackType, attackStrength)
{
    this->m_electricPower = electricPower;
}

ElectricPokemon::~ElectricPokemon()
{
    std::cout << "Classe derivada : Pokémon elétrico " << this->GetName()
              << " diz: Adeus!" << std::endl;
}

double ElectricPokemon::CalculateDamage()
{
    return this->m_electricPower * this->GetAttackStrength();
}

void ElectricPokemon::SayAttackType() const
{
    std::cout << this->GetAttackType() << "! Bzzzz!" << std::endl;
}
