/*
 * Filename: pokemon.cc
 * Created on: May  1, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "pokemon.h"

Pokemon::Pokemon(std::string name, std::string attackType, double attackStrength)
{
    this->m_name           = name;
    this->m_attackType     = attackType;
    this->m_attackStrength = attackStrength;
    this->m_hp             = 100;
}

Pokemon::~Pokemon()
{
    std::cout << "Classe base : Pokémon " << this->m_name << " foi destruído!"
              << std::endl;
}

void Pokemon::ReceiveAttack(double damage)
{
    if (this->m_hp == 0)
    {
        std::cout << this->m_name << " já morreu. Não chute Pokémon morto!"
                  << std::endl;
        return;
    }

    this->m_hp = std::max(0.0, m_hp - damage);

    if (this->m_hp == 0)
    {
        std::cout << this->m_name << " Faliceu! ;-;" << std::endl;
    }
}

void Pokemon::Attack(Pokemon* target)
{
    if (this->m_hp == 0)
    {
        std::cout << this->m_name << " já partiu dessa pra melhor e não pode atacar!"
                  << std::endl;
        return;
    }

    this->PrintInfo();

    double damage = this->CalculateDamage();

    std::cout << "Dano: " << damage << std::endl;

    target->ReceiveAttack(damage);

    target->PrintInfo();
}

std::string Pokemon::GetName() const
{
    return this->m_name;
}

std::string Pokemon::GetAttackType() const
{
    return this->m_attackType;
}

double Pokemon::GetAttackStrength() const
{
    return this->m_attackStrength;
}

double Pokemon::GetHp() const
{
    return this->m_hp;
}

void Pokemon::SayName() const
{
    std::cout << this->m_name << std::endl;
}

void Pokemon::SayAttackType() const
{
    std::cout << this->m_attackType << std::endl;
}

void Pokemon::PrintInfo() const
{
    std::cout << "Pokémon: " << this->m_name << std::endl;
    std::cout << "Tipo de ataque: ";
    this->SayAttackType();
    std::cout << "Potência do ataque: " << this->m_attackStrength << std::endl;
    std::cout << "HP: " << this->m_hp << std::endl;
}
