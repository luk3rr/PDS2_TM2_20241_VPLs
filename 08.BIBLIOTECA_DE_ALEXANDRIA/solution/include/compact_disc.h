/*
 * Filename: compact_disc.h
 * Created on: May  8, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef CD_H_
#define CD_H_

#include "item.h"
#include <cstddef>

class CompactDisc : public Item
{
    private:
        std::size_t m_tracks;
        std::size_t m_duration;

    public:
        CompactDisc(std::size_t id,
                    std::size_t availableCopies,
                    std::size_t tracks,
                    std::size_t duration,
                    std::string title,
                    std::string artist,
                    std::string date);
        ~CompactDisc();

        std::size_t GetTracks() const;
        std::size_t GetDuration() const;

        void PrintInfo();
};

#endif // CD_H_
