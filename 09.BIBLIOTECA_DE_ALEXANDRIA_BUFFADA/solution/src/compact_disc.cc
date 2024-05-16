/*
 * Filename: compact_disc.cc
 * Created on: May  8, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "compact_disc.h"

CompactDisc::CompactDisc(std::size_t id,
                         std::size_t availableCopies,
                         std::size_t tracks,
                         std::size_t duration,
                         std::string title,
                         std::string author,
                         std::string date)
    : Item(id, availableCopies, title, author, date, "CD")
{
    this->m_tracks   = tracks;
    this->m_duration = duration;
}

CompactDisc::~CompactDisc()
{
    std::cout << "CD " << this->GetID() << " diz: Ouça-me amanhã!" << std::endl;
}

std::size_t CompactDisc::GetTracks() const
{
    return this->m_tracks;
}

std::size_t CompactDisc::GetDuration() const
{
    return this->m_duration;
}

#include <iomanip>
#include <iostream>

void CompactDisc::PrintInfo()
{
    std::cout << "ITEM: " << this->GetItemType() << std::endl;
    std::cout << "ID: " << this->GetID() << std::endl;
    std::cout << "TÍTULO: " << this->GetTitle() << std::endl;
    std::cout << "ARTISTA: " << this->GetAuthor() << std::endl;
    std::cout << "FAIXAS: " << this->GetTracks() << std::endl;

    // Formatar a duração no formato hh:mm:ss
    int duration = this->GetDuration();
    int hours    = duration / 3600;
    int minutes  = (duration % 3600) / 60;
    int seconds  = duration % 60;

    std::cout << "DURAÇÃO: " << std::setfill('0') << std::setw(2) << hours << ":"
              << std::setfill('0') << std::setw(2) << minutes << ":"
              << std::setfill('0') << std::setw(2) << seconds << std::endl;

    std::cout << "DATA: " << this->GetDate() << std::endl;
    std::cout << "CÓPIAS DISPONÍVEIS: " << this->GetAvailableCopies() << std::endl;
    std::cout << "CÓPIAS RESERVADAS: " << this->GetLoanedCopies() << std::endl;
}
