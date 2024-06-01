/*
 * Filename: pokemon_aquatic.cc
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "pokemon_aquatic.h"

AquaticPokemon::AquaticPokemon(std::string name,
                               std::string attackType,
                               double      aquaticPower,
                               double      attackStrength)
    : Pokemon(name, attackType, attackStrength)
{
    this->m_aquaticPower = aquaticPower;
}

AquaticPokemon::~AquaticPokemon()
{
    std::cout << "Classe derivada : Pokémon aquático " << this->GetName()
              << " diz: Adeus!" << std::endl;
}

double AquaticPokemon::CalculateDamage()
{
    return this->m_aquaticPower * this->GetAttackStrength();
}

void AquaticPokemon::SayAttackType() const
{
    std::cout << this->GetAttackType() << "! Splash!" << std::endl;
}
