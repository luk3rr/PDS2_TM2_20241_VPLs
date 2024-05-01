/*
 * Filename: pokemon.h
 * Created on: April 30, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef POKEMON_H_
#define POKEMON_H_

#include <string>

/**
 * @brief Base class for all pokemons
 **/
class Pokemon
{
    private:
        std::string m_name;
        std::string m_attackType;
        double      m_hp;
        double      m_attackStrength;

    public:
        /**
         * @brief Constructor
         * @param name Name of the pokemon
         * @param attackType Type of attack of the pokemon
         **/
        Pokemon(std::string name, std::string attackType, double attackStrength);

        /**
         * @brief Destructor
         **/
        virtual ~Pokemon();

        /**
         * @brief Calculate the damage of an attack
         **/
        virtual double CalculateDamage() = 0;

        /**
         * @brief Attack another pokemon
         * @param other Pokemon to be attacked
         **/
        void Attack(Pokemon* other);

        /**
         * @brief Receive an attack from another pokemon
         * @param damage Amount of damage received
         **/
        void ReceiveAttack(double damage);

        /**
         * @brief Get the name of the pokemon
         * @return Name of the pokemon
         **/
        std::string GetName() const;

        /**
         * @brief Get the type of attack of the pokemon
         * @return Type of attack of the pokemon
         **/
        std::string GetAttackType() const;

        /**
         * @brief Get the attack strength of the pokemon
         * @return Attack strength of the pokemon
         **/
        double GetAttackStrength() const;

        /**
         * @brief Get the health points of the pokemon
         * @return Health points of the pokemon
         **/
        double GetHp() const;

        /**
         * @brief Say the pokemon's name
         **/
        void SayName() const;

        /**
         * @brief Say the pokemon's attack type
         **/
        virtual void SayAttackType() const;

        /**
         * @brief Print the information of the pokemon
         **/
        void PrintInfo() const;
};

#endif // POKEMON_H_
