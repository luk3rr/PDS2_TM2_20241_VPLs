/*
 * Filename: periodic.cc
 * Created on: May 10, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "periodic.h"
#include <cstddef>

Periodic::Periodic(std::size_t id,
                   std::size_t availableCopies,
                   std::size_t volume,
                   std::size_t number,
                   std::string title,
                   std::string date,
                   std::string editor,
                   std::string topics,
                   std::string type) : Item(id, availableCopies, title, editor, date, type)
{
    this->m_volume = volume;
    this->m_number = number;
    this->m_topics = topics;
}

Periodic::~Periodic()
{
    std::cout << this->GetItemType() << " " << this->GetID() << " diz: Leia-me amanhã!" << std::endl;
}

std::size_t Periodic::GetVolume() const
{
    return this->m_volume;
}

std::size_t Periodic::GetNumber() const
{
    return this->m_number;
}

std::string Periodic::GetTopics() const
{
    return this->m_topics;
}

void Periodic::PrintInfo()
{
    std::cout << "ITEM: " << this->GetItemType() << std::endl;
    std::cout << "ID: " << this->GetID() << std::endl;
    std::cout << "TÍTULO: " << this->GetTitle() << std::endl;
    std::cout << "EDITORA: " << this->GetAuthor() << std::endl;
    std::cout << "TÓPICOS: " << this->GetTopics() << std::endl;
    std::cout << "DATA: " << this->GetDate() << std::endl;
    std::cout << "CÓPIAS DISPONÍVEIS: " << this->GetAvailableCopies() << std::endl;
    std::cout << "CÓPIAS RESERVADAS: " << this->GetLoanedCopies() << std::endl;
}
