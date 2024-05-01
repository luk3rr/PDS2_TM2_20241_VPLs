/*
 * Filename: trainer.cc
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "trainer.h"

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

void Trainer::AddAquaticPokemon(std::string name,
                                std::string attackType,
                                double      aquaticPower,
                                double      attackStrength)
{
    Pokemon* p = new AquaticPokemon(name, attackType, aquaticPower, attackStrength);
    this->m_pokemons.push_back(p);
}

void Trainer::AddElectricPokemon(std::string name,
                                 std::string attackType,
                                 double      electricPower,
                                 double      attackStrength)
{
    Pokemon* p = new ElectricPokemon(name, attackType, electricPower, attackStrength);
    this->m_pokemons.push_back(p);
}

void Trainer::AddExplosivePokemon(std::string name,
                                  std::string attackType,
                                  double      explosivePower,
                                  double      attackStrength)
{
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
    std::cerr << "Pokemon not found" << std::endl;
    return nullptr;
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
