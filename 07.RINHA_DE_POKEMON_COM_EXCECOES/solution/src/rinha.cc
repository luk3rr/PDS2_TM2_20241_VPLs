/*
 * Filename: rinha.cc
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "rinha.h"
#include "rinhaExcpt.h"

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
    try
    {
        this->GetTrainer(name);
        throw TrainerAlreadyExists(name);
    }
    catch (TrainerNotFound& e)
    {
        Trainer* trainer = new Trainer(name);
        this->m_trainers.push_back(trainer);
    }
}

void Rinha::AddElectricPokemon(std::string trainerName,
                               std::string pokemonName,
                               double      electricPower,
                               double      attackStrength)
{
    Trainer* trainer = this->GetTrainer(trainerName);

    trainer->AddElectricPokemon(pokemonName, "Elétrico", electricPower, attackStrength);
}

void Rinha::AddAquaticPokemon(std::string trainerName,
                              std::string pokemonName,
                              double      aquaticPower,
                              double      attackStrength)
{
    Trainer* trainer = this->GetTrainer(trainerName);

    trainer->AddAquaticPokemon(pokemonName, "Aquático", aquaticPower, attackStrength);
}

void Rinha::AddExplosivePokemon(std::string trainerName,
                                std::string pokemonName,
                                double      explosivePower,
                                double      attackStrength)
{
    Trainer* trainer = this->GetTrainer(trainerName);

    trainer->AddExplosivePokemon(pokemonName,
                                 "Explosivo",
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

    throw TrainerNotFound(name);
}

void Rinha::Fight(std::string trainerName1,
                  std::string pokemonName1,
                  std::string trainerName2,
                  std::string pokemonName2)
{
    Trainer* trainer1 = this->GetTrainer(trainerName1);
    Trainer* trainer2 = this->GetTrainer(trainerName2);

    Pokemon* pokemon1 = trainer1->UsePokemon(pokemonName1);
    Pokemon* pokemon2 = trainer2->UsePokemon(pokemonName2);

    std::cout << "### RINHA ###" << std::endl;
    std::cout << trainerName1 << " (" << pokemonName1 << ") vs. " << trainerName2
              << " (" << pokemonName2 << ")" << std::endl;

    pokemon1->Attack(pokemon2);

    std::cout << "#############" << std::endl;
}
