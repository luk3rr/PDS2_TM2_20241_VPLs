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

CompactDisc::~CompactDisc() { }

std::size_t CompactDisc::GetTracks() const
{
    return this->m_tracks;
}

std::size_t CompactDisc::GetDuration() const
{
    return this->m_duration;
}

void CompactDisc::PrintInfo()
{
    std::cout << "ITEM: " << this->GetItemType() << std::endl;
    std::cout << "ID: " << this->GetID() << std::endl;
    std::cout << "TITLE: " << this->GetTitle() << std::endl;
    std::cout << "ARTIST: " << this->GetAuthor() << std::endl;
    std::cout << "TRACKS: " << this->GetTracks() << std::endl;
    std::cout << "DURATION: " << this->GetDuration() / 3600 << ":"
              << (this->GetDuration() % 3600) / 60 << ":" << this->GetDuration() % 60
              << std::endl;
    std::cout << "DATE: " << this->GetDate() << std::endl;
    std::cout << "AVAILABLE COPIES: " << this->GetAvailableCopies() << std::endl;
    std::cout << "LOANED COPIES: " << this->GetLoanedCopies() << std::endl;
}
