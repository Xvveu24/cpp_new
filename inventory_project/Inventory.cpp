#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory(int size) : size(size > 0 ? size : 0), items(0)
{
    if (this->size > 0)
    {
        items = new Item[this->size];
    }
}

Inventory::Inventory(const Inventory& other)
    : size(other.size), items(other.size > 0 ? new Item[other.size] : 0)
{
    for (int i = 0; i < size; i++)
    {
        items[i] = other.items[i];
    }
}

Inventory::~Inventory()
{
    delete[] items;
}

void Inventory::setItem(int index, const Item& item)
{
    if (index >= 0 && index < size)
    {
        items[index] = item;
    }
}

void Inventory::print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". ";
        items[i].print();
    }
}
