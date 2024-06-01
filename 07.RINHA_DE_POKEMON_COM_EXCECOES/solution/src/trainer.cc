/*
 * Filename: trainer.cc
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "trainer.h"
#include "rinhaExcpt.h"

Trainer::Trainer(std::string name)
{
    this->m_name = name;
}

Trainer::~Trainer()
{
    for (auto& p : this->m_pokemons)
    {
        delete p;
    }

    std::cout << "Treinador " << this->m_name << " foi destruído!" << std::endl;
}

bool Trainer::FindPokemon(std::string name)
{
    for (auto& p : m_pokemons)
    {
        if (p->GetName() == name)
        {
            return true;
        }
    }
    return false;
}

void Trainer::AddAquaticPokemon(std::string name,
                                std::string attackType,
                                double      aquaticPower,
                                double      attackStrength)
{
    if (this->FindPokemon(name))
    {
        throw PokemonAlreadyExists(name, this->m_name);
    }

    if (aquaticPower < 0)
    {
        throw NegativePower();
    }

    if (attackStrength < 0)
    {
        throw NegativeStrength();
    }

    Pokemon* p = new AquaticPokemon(name, attackType, aquaticPower, attackStrength);
    this->m_pokemons.push_back(p);
}

void Trainer::AddElectricPokemon(std::string name,
                                 std::string attackType,
                                 double      electricPower,
                                 double      attackStrength)
{
    if (this->FindPokemon(name))
    {
        throw PokemonAlreadyExists(name, this->m_name);
    }

    if (electricPower < 0)
    {
        throw NegativePower();
    }

    if (attackStrength < 0)
    {
        throw NegativeStrength();
    }

    Pokemon* p = new ElectricPokemon(name, attackType, electricPower, attackStrength);
    this->m_pokemons.push_back(p);
}

void Trainer::AddExplosivePokemon(std::string name,
                                  std::string attackType,
                                  double      explosivePower,
                                  double      attackStrength)
{
    if (this->FindPokemon(name))
    {
        throw PokemonAlreadyExists(name, this->m_name);
    }

    if (explosivePower < 0)
    {
        throw NegativePower();
    }

    if (attackStrength < 0)
    {
        throw NegativeStrength();
    }

    Pokemon* p = new ExplosivePokemon(name, attackType, explosivePower, attackStrength);
    this->m_pokemons.push_back(p);
}

std::string Trainer::GetName()
{
    return this->m_name;
}

Pokemon* Trainer::UsePokemon(std::string name)
{
    for (auto& p : m_pokemons)
    {
        if (p->GetName() == name)
        {
            return p;
        }
    }

    throw PokemonNotFound(name, this->m_name);
}

void Trainer::PrintInfo()
{
    std::string line = "----------";

    std::cout << "Treinador: " << this->m_name << std::endl;

    if (this->m_pokemons.size() == 0)
    {
        std::cout << line << std::endl;
        std::cout << "Nenhum pokémon encontrado :(" << std::endl;
    }
    else
    {
        for (auto& p : m_pokemons)
        {
            std::cout << line << std::endl;
            p->PrintInfo();
        }
    }
    std::cout << line << std::endl;
}
