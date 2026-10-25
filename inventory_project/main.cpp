#include <iostream>
#include "Inventory.h"
using namespace std;

int main()
{
    Inventory bag(3);

    Item sword("Iron sword", Weapon);
    Item potion("Health potion", Potion);
    Item bread("Bread", Food);

    bag.setItem(0, sword);
    bag.setItem(1, potion);
    bag.setItem(2, bread);

    cout << "Inventory:\n";
    bag.print();

    Inventory copyBag(bag);

    cout << "\nCopy:\n";
    copyBag.print();
}
