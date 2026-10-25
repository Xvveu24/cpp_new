#include "Item.h"
#include <iostream>
using namespace std;

Item::Item() : name(), type(None) {}

Item::Item(const char* name, ItemClass type) : name(name), type(type) {}

void Item::print() const
{
    cout << name.c_str() << " - ";

    switch (type)
    {
    case Weapon:
        cout << "Weapon";
        break;
    case Potion:
        cout << "Potion";
        break;
    case Food:
        cout << "Food";
        break;
    default:
        cout << "None";
    }

    cout << '\n';
}
