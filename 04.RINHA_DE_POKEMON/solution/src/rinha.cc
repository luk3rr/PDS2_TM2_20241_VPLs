/*
 * Filename: rinha.cc
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "rinha.h"

Rinha::Rinha() { }

Rinha::~Rinha()
{
    for (auto trainer : this->m_trainers)
    {
        delete trainer;
    }

    std::cout << "Rinha destruída pela Polícia Federal!" << std::endl;
}

void Rinha::AddTrainer(std::string name)
{
    Trainer* trainer = new Trainer(name);
    this->m_trainers.push_back(trainer);
}

void Rinha::AddElectricPokemon(std::string trainerName,
                               std::string pokemonName,
                               std::string attackType,
                               double      electricPower,
                               double      attackStrength)
{
    Trainer* trainer = this->GetTrainer(trainerName);

    if (trainer == nullptr)
    {
        std::cerr << "Trainer not found" << std::endl;
        return;
    }

    trainer->AddElectricPokemon(pokemonName, attackType, electricPower, attackStrength);
}

void Rinha::AddAquaticPokemon(std::string trainerName,
                              std::string pokemonName,
                              std::string attackType,
                              double      aquaticPower,
                              double      attackStrength)
{
    Trainer* trainer = this->GetTrainer(trainerName);

    if (trainer == nullptr)
    {
        std::cerr << "Trainer not found" << std::endl;
        return;
    }

    trainer->AddAquaticPokemon(pokemonName, attackType, aquaticPower, attackStrength);
}

void Rinha::AddExplosivePokemon(std::string trainerName,
                                std::string pokemonName,
                                std::string attackType,
                                double      explosivePower,
                                double      attackStrength)
{
    Trainer* trainer = this->GetTrainer(trainerName);

    if (trainer == nullptr)
    {
        std::cerr << "Trainer not found" << std::endl;
        return;
    }

    trainer->AddExplosivePokemon(pokemonName,
                                 attackType,
                                 explosivePower,
                                 attackStrength);
}

Trainer* Rinha::GetTrainer(std::string name)
{
    for (auto trainer : this->m_trainers)
    {
        if (trainer->GetName() == name)
        {
            return trainer;
        }
    }

    return nullptr;
}

void Rinha::Fight(std::string nameTrainer1,
                  std::string namePokemon1,
                  std::string nameTrainer2,
                  std::string namePokemon2)
{
    Trainer* trainer1 = this->GetTrainer(nameTrainer1);
    Trainer* trainer2 = this->GetTrainer(nameTrainer2);

    if (trainer1 == nullptr or trainer2 == nullptr)
    {
        std::cerr << "Trainer not found" << std::endl;
        return;
    }

    Pokemon* pokemon1 = trainer1->UsePokemon(namePokemon1);
    Pokemon* pokemon2 = trainer2->UsePokemon(namePokemon2);

    if (pokemon1 == nullptr or pokemon2 == nullptr)
    {
        std::cerr << "Pokemon not found" << std::endl;
        return;
    }

    std::cout << "### RINHA ###" << std::endl;
    std::cout << nameTrainer1 << " (" << namePokemon1 << ") vs. " << nameTrainer2
              << " (" << namePokemon2 << ")" << std::endl;

    pokemon1->Attack(pokemon2);

    std::cout << "#############" << std::endl;
}
