/*
 * Filename: item.cc
 * Created on: May  8, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <cstddef>
#include <iostream>

class Item
{
    private:
        std::size_t m_id;
        std::size_t m_availableCopies;
        std::size_t m_loanedCopies;
        std::string m_title;
        std::string m_author;
        std::string m_date;
        std::string m_itemType;

    public:
        Item(std::size_t id,
             std::size_t availableCopies,
             std::string title,
             std::string author,
             std::string date,
             std::string itemType);

        virtual ~Item();

        std::size_t GetID() const;
        std::size_t GetAvailableCopies() const;
        std::size_t GetLoanedCopies() const;
        std::string GetTitle() const;
        std::string GetAuthor() const;
        std::string GetDate() const;
        std::string GetItemType() const;

        // Reserva um item
        bool Reserve();

        // Libera um item que foi reservado
        void Release();

        virtual void PrintInfo();
};

#endif // ITEM_H_
