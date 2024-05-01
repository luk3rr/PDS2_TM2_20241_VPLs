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

    public:
        /**
         * @brief Constructor
         * @param name Name of the pokemon
         * @param attackType Type of attack of the pokemon
         * @param hp Initial health points of the pokemon
         **/
        Pokemon(std::string name, std::string attackType, double hp);

        /**
         * @brief Destructor
         **/
        virtual ~Pokemon();

        /**
         * @brief Attack another pokemon
         * @param other Pokemon to be attacked
         **/
        virtual void Attack(Pokemon* other) = 0;

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
         * @brief Get the health points of the pokemon
         * @return Health points of the pokemon
         **/
        double GetHp() const;

        /**
         * @brief Set the health points of the pokemon
         * @param hp New health points of the pokemon
         **/
        void GetHp(double hp);

        /**
         * @brief Receive an attack from another pokemon
         * @param damage Amount of damage received
         **/
        void ReceiveAttack(double damage);

        /**
         * @brief Say the pokemon's name
         **/
        void SayName() const;

        /**
         * @brief Say the pokemon's attack type
         **/
        void SayAttackType() const;
};

#endif // POKEMON_H_
