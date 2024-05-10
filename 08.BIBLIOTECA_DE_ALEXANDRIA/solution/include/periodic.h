/*
 * Filename: periodic.h
 * Created on: May 10, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef PERIODICS_H_
#define PERIODICS_H_

#include "item.h"
#include <cstddef>

class Periodic : public Item
{
    private:
        std::size_t m_volume;
        std::size_t m_number;
        std::string m_topics;

    public:
        Periodic(std::size_t id,
                 std::size_t availableCopies,
                 std::size_t volume,
                 std::size_t number,
                 std::string title,
                 std::string date,
                 std::string editor,
                 std::string topics,
                 std::string type);

        ~Periodic();

        std::size_t GetVolume() const;
        std::size_t GetNumber() const;
        std::string GetTopics() const;

        void PrintInfo();
};

#endif // PERIODICS_H_
