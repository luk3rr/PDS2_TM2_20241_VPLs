/*
 * Filename: rinhaExcpt.h
 * Created on: May 31, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef RINHAEXCPT_H_
#define RINHAEXCPT_H_

#include <exception>
#include <iostream>
#include <string>

class TrainerAlreadyExists : public std::exception
{
    private:
        std::string m_name;
        std::string m_message;

    public:
        TrainerAlreadyExists(std::string name)
            : m_name(name), m_message("Treinador " + m_name + " já existe (-_-)")
        { }

        const char* what() const noexcept override
        {
            return m_message.c_str();
        }
};

class PokemonAlreadyExists : public std::exception
{
    private:
        std::string m_pokemonName;
        std::string m_trainerName;
        std::string m_message;

    public:
        PokemonAlreadyExists(std::string pokemonName, std::string trainerName)
        {
            m_pokemonName = pokemonName;
            m_trainerName = trainerName;
            m_message = "Pokémon " + m_pokemonName + " já existe no time do treinador " + m_trainerName + " (-_-)";
        }

        const char* what() const noexcept override
        {
            return m_message.c_str();
        }
};

class PokemonNotFound : public std::exception
{
    private:
        std::string m_pokemonName;
        std::string m_trainerName;
        std::string m_message;

    public:
        PokemonNotFound(std::string pokemonName, std::string trainerName)
        {
            m_pokemonName = pokemonName;
            m_trainerName = trainerName;
            m_message = "Pokémon " + m_pokemonName + " não encontrado no time do treinador " + m_trainerName + " o.O";
        }

        const char* what() const throw()
        {
            return m_message.c_str();
        }
};

class TrainerNotFound : public std::exception
{
    private:
        std::string m_name;
        std::string m_message;

    public:
        TrainerNotFound(std::string name)
            : m_name(name), m_message("Treinador " + m_name + " não encontrado o.O")
        { }

        const char* what() const noexcept override
        {
            return m_message.c_str();
        }
};

class NegativePower : public std::exception
{
    public:
        const char* what() const noexcept override
        {
            return "Poder do ataque não pode ser negativo '-'";
        }
};

class NegativeStrength : public std::exception
{
    public:
        const char* what() const noexcept override
        {
            return "Potência do ataque não pode ser negativa '-'";
        }
};

#endif // RINHAEXCPT_H_
