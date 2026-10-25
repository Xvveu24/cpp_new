#include <iostream>
#include "Player.h"
using namespace std;

int main()
{
    Player first;
    Player second("Alex", 75, 3);
    Player third("Mira", 40, 2);

    cout << "Players: " << Player::getPlayerCount() << "\n\n";

    first.setName("New player");
    first.takeDamage(25);
    first.heal(10);
    first.levelUp();

    second.setHealth(-5);
    second.heal(30);
    second.levelUp();

    first.printStats();
    cout << '\n';
    second.printStats();
    cout << '\n';
    third.printStats();

    cout << "\nPlayers: " << Player::getPlayerCount();
}
