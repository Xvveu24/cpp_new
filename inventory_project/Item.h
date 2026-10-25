#pragma once
#include "String.h"

enum ItemClass
{
    Weapon,
    Potion,
    Food,
    None
};

class Item
{
private:
    String name;
    ItemClass type;

public:
    Item();
    Item(const char* name, ItemClass type);

    void print() const;
};
