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
                   std::string type,
                   std::string topics) : Item(id, availableCopies, title, editor, date, type)
{
    this->m_volume = volume;
    this->m_number = number;
    this->m_topics = topics;
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
    std::cout << "TITLE: " << this->GetTitle() << std::endl;
    std::cout << "EDITOR: " << this->GetAuthor() << std::endl;
    std::cout << "TOPICS: " << this->GetTopics() << std::endl;
    std::cout << "DATE: " << this->GetDate() << std::endl;
    std::cout << "AVAILABLE COPIES: " << this->GetAvailableCopies() << std::endl;
    std::cout << "LOANED COPIES: " << this->GetLoanedCopies() << std::endl;
}
