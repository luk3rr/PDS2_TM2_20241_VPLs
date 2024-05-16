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
#include <utility>
#include <vector>

#include "book.h"
#include "compact_disc.h"
#include "item.h"
#include "periodic.h"
#include "user.h"

class Library
{
    private:
        std::vector<Item*> m_items;
        std::vector<User*> m_users;
        std::vector<std::pair<std::pair<Item*, User*>, bool>> m_reservations;

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

        void AddUser(std::string name, std::string email, std::string cpf);

        Item* SearchItem(std::size_t id);
        Item* SearchItem(std::string title);

        User* SearchUser(std::size_t id);

        void Reserve(std::size_t item_id, std::size_t user_id);
        void Reserve(std::string item_title, std::size_t user_id);
        void Release(std::size_t item_id, std::size_t user_id);

        void PrintCollection();
        void PrintUsers();
        void PrintReservations();
};

#endif // LIBRARY_H_
