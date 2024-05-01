/*
 * Filename: rinha.h
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef RINHA_H_
#define RINHA_H_

#include "trainer.h"

class Rinha
{
    private:
        std::vector<Trainer*> m_trainers;

    public:
        Rinha();
        ~Rinha();

        /**
         * @brief Add a new trainer to the rinha
         **/
        void AddTrainer(std::string name);

        /**
         * @brief Add a new electric pokemon to a trainer
         * @param trainerName The name of the trainer
         * @param pokemonName The name of the pokemon
         * @param attackType The attack type of the pokemon
         * @param electricPower The electric power of the pokemon
         * @param attackStrength The attack strength of the pokemon
         **/
        void AddElectricPokemon(std::string trainerName,
                                std::string pokemonName,
                                std::string attackType,
                                double      electricPower,
                                double      attackStrength);

        /**
         * @brief Add a new aquatic pokemon to a trainer
         * @param trainerName The name of the trainer
         * @param pokemonName The name of the pokemon
         * @param attackType The attack type of the pokemon
         * @param aquaticPower The aquatic power of the pokemon
         * @param attackStrength The attack strength of the pokemon
         **/
        void AddAquaticPokemon(std::string trainerName,
                               std::string pokemonName,
                               std::string attackType,
                               double      aquaticPower,
                               double      attackStrength);

        /**
         * @brief Add a new explosive pokemon to a trainer
         * @param trainerName The name of the trainer
         * @param pokemonName The name of the pokemon
         * @param attackType The attack type of the pokemon
         * @param explosivePower The explosive power of the pokemon
         * @param attackStrength The attack strength of the pokemon
         **/
        void AddExplosivePokemon(std::string trainerName,
                                 std::string pokemonName,
                                 std::string attackType,
                                 double      explosivePower,
                                 double      attackStrength);

        /**
         * @brief Find a trainer by its name
         * @param name The name of the trainer
         * @return A pointer to the trainer or nullptr if the trainer is not found
         **/
        Trainer* GetTrainer(std::string name);

        /**
         * @brief Battle between two pokemons
         * @param nameTrainer1 The name of the first trainer
         * @param namePokemon1 The name of the pokemon of the first trainer
         * @param nameTrainer2 The name of the second trainer
         * @param namePokemon2 The name of the pokemon of the second trainer
         **/
        void Fight(std::string nameTrainer1,
                   std::string namePokemon1,
                   std::string nameTrainer2,
                   std::string namePokemon2);
};

#endif // RINHA_H_
