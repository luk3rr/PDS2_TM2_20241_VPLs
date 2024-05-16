/*
 * Filename: library.cc
 * Created on: May 10, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "library.h"
#include <cstddef>
#include <utility>

Library::Library() { }

Library::~Library()
{
    for (auto item : this->m_items)
    {
        delete item;
    }

    for (auto user : this->m_users)
    {
        delete user;
    }

    std::cout << "Bye!" << std::endl;
}

void Library::AddBook(std::size_t copies,
                      std::size_t pages,
                      std::string title,
                      std::string author,
                      std::string isbn,
                      std::string date,
                      std::string genre,
                      std::string publisher)
{
    this->m_items.push_back(new Book(this->m_items.size(),
                                     copies,
                                     pages,
                                     title,
                                     author,
                                     isbn,
                                     date,
                                     genre,
                                     publisher));
}

void Library::AddPeriodic(std::size_t copies,
                          std::size_t volume,
                          std::size_t number,
                          std::string title,
                          std::string date,
                          std::string editor,
                          std::string topics,
                          std::string type)
{
    this->m_items.push_back(new Periodic(this->m_items.size(),
                                         copies,
                                         volume,
                                         number,
                                         title,
                                         date,
                                         editor,
                                         topics,
                                         type));
}

void Library::AddCD(std::size_t copies,
                    std::size_t tracks,
                    std::size_t duration,
                    std::string title,
                    std::string artist,
                    std::string date)
{
    this->m_items.push_back(new CompactDisc(this->m_items.size(),
                                            copies,
                                            tracks,
                                            duration,
                                            title,
                                            artist,
                                            date));
}

void Library::AddUser(std::string name, std::string email, std::string cpf)
{
    this->m_users.push_back(new User(this->m_users.size(), name, email, cpf));
}

Item* Library::SearchItem(std::size_t id)
{
    for (auto item : this->m_items)
    {
        if (item->GetID() == id)
        {
            return item;
        }
    }

    return nullptr;
}

Item* Library::SearchItem(std::string title)
{
    std::vector<Item*> items_found;

    for (auto item : this->m_items)
    {
        if (item->GetTitle() == title)
        {
            items_found.push_back(item);
        }
    }

    if (items_found.empty())
    {
        return nullptr;
    }
    else if (items_found.size() == 1)
    {
        return items_found[0];
    }
    else
    {
        std::cout << "Vários itens com o mesmo título encontrados:" << std::endl;
        std::cout << "----------" << std::endl;

        for (auto item : items_found)
        {
            item->PrintInfo();
            std::cout << "----------" << std::endl;
        }

        return nullptr;
    }
}

User* Library::SearchUser(std::size_t id)
{
    for (auto user : this->m_users)
    {
        if (user->GetID() == id)
        {
            return user;
        }
    }

    return nullptr;
}

void Library::Reserve(std::size_t item_id, std::size_t user_id)
{
    Item* item = this->SearchItem(item_id);

    if (item == nullptr)
    {
        std::cout << "Item " << item_id << " não encontrado o.O" << std::endl;
        return;
    }

    User* user = this->SearchUser(user_id);

    if (user == nullptr)
    {
        std::cout << "Usuário " << user_id << " não encontrado o.O" << std::endl;
        return;
    }

    this->m_reservations.push_back(std::make_pair(std::make_pair(item, user), false));

    item->Reserve();

    std::cout << "Usuário " << user->GetName() << " reservou o item "
              << item->GetTitle() << " com sucesso!" << std::endl;
}

void Library::Reserve(std::string item_title, std::size_t user_id)
{
    Item* item = this->SearchItem(item_title);

    if (item == nullptr)
    {
        std::cout << "Item " << item_title << " não encontrado o.O" << std::endl;
        return;
    }

    User* user = this->SearchUser(user_id);
    if (user == nullptr)
    {
        std::cout << "Usuário " << user_id << " não encontrado o.O" << std::endl;
        return;
    }

    this->m_reservations.push_back(std::make_pair(std::make_pair(item, user), false));
    item->Reserve();

    std::cout << "Usuário " << user->GetName() << " reservou o item "
              << item->GetTitle() << " com sucesso!" << std::endl;
}

void Library::Release(std::size_t item_id, std::size_t user_id)
{
    Item* item = this->SearchItem(item_id);

    if (item == nullptr)
    {
        std::cout << "Item " << item_id << " não encontrado o.O" << std::endl;
        return;
    }

    User* user = this->SearchUser(user_id);

    if (user == nullptr)
    {
        std::cout << "Usuário " << user_id << " não encontrado o.O" << std::endl;
        return;
    }

    bool found = false;

    for (auto& reservation : this->m_reservations)
    {
        if (reservation.first.first->GetID() == item_id and
            reservation.first.second->GetID() == user_id)
        {
            reservation.second = true;

            item->Release();

            std::cout << "Usuário " << user->GetName() << " devolveu o item "
                      << item->GetTitle() << " com sucesso!" << std::endl;

            found = true;
            break;
        }
    }

    if (not found)
    {
        std::cout << "Usuário " << user->GetName() << " não reservou o item "
                  << item->GetTitle() << " o.O" << std::endl;
    }
}

void Library::PrintCollection()
{
    if (this->m_items.empty())
    {
        std::cout << "Estamos sem itens, mas você pode fazer uma doação ;-;"
                  << std::endl;
    }
    else
    {

        std::cout << "----------" << std::endl;
        for (auto item : this->m_items)
        {
            item->PrintInfo();
            std::cout << "----------" << std::endl;
        }
    }
}

void Library::PrintUsers()
{
    if (this->m_users.empty())
    {
        std::cout << "Não há usuários cadastrados. Acho que estão todos no TikTok -.-"
                  << std::endl;
    }
    else
    {
        std::cout << "----------" << std::endl;
        for (auto user : this->m_users)
        {
            user->PrintInfo();
            std::cout << "----------" << std::endl;
        }
    }
}

void Library::PrintReservations()
{
    if (this->m_reservations.empty())
    {
        std::cout << "Não há reservas no momento. Hoje em dia as pessoas só pensam em "
                     "TikTok -.-"
                  << std::endl;
    }
    else
    {
        std::cout << "----------" << std::endl;
        for (auto reservation : this->m_reservations)
        {
            std::cout << "Item: " << reservation.first.first->GetTitle() << std::endl;
            std::cout << "Usuário: " << reservation.first.second->GetName()
                      << std::endl;
            std::cout << "Status: " << (reservation.second ? "Devolvido" : "Reservado")
                      << std::endl;
            std::cout << "----------" << std::endl;
        }
    }
}
