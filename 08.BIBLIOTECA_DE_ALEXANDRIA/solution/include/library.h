/*
 * Filename: library.h
 * Created on: May 10, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

#include "book.h"
#include "compact_disc.h"
#include "item.h"
#include "periodic.h"

class Library
{
    private:
        std::vector<Item*> m_items;

    public:
        Library();
        ~Library();

        void AddBook(std::size_t copies,
                     std::size_t pages,
                     std::string title,
                     std::string author,
                     std::string isbn,
                     std::string date,
                     std::string genre,
                     std::string publisher);

        void AddPeriodic(std::size_t copies,
                         std::size_t volume,
                         std::size_t number,
                         std::string title,
                         std::string date,
                         std::string editor,
                         std::string topics,
                         std::string type);

        void AddCD(std::size_t copies,
                   std::size_t tracks,
                   std::size_t duration,
                   std::string title,
                   std::string artist,
                   std::string date);

        Item* Search(std::size_t id);
        Item* Search(std::string title);

        void Reserve(std::size_t id);
        void Reserve(std::string title);

        void Release(std::size_t id);

        void PrintCollection();
};

#endif // LIBRARY_H_
