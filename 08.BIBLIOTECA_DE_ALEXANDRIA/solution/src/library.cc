/*
 * Filename: library.cc
 * Created on: May 10, 2024
 * Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
 */

#include "library.h"

Library::Library() { }

Library::~Library()
{
    for (auto item : this->m_items)
    {
        delete item;
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

Item* Library::Search(std::size_t id)
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

Item* Library::Search(std::string title)
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

void Library::Reserve(std::size_t id)
{
    Item* item = this->Search(id);

    if (item != nullptr)
    {
        item->Reserve();
    }
    else
    {
        std::cout << "Item " << id << " não encontrado o.O" << std::endl;
    }
}

void Library::Reserve(std::string title)
{
    Item* item = this->Search(title);

    if (item != nullptr)
    {
        item->Reserve();
    }
    else
    {
        std::cout << "Item " << title << " não encontrado o.O" << std::endl;
    }
}

void Library::Release(std::size_t id)
{
    Item* item = this->Search(id);

    if (item != nullptr)
    {
        item->Release();
    }
    else
    {
        std::cout << "Item " << id << " não encontrado o.O" << std::endl;
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
