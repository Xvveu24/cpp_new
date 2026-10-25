#include "Player.h"
#include <iostream>
#include <cstring>
using namespace std;

int Player::playerCount = 0;

Player::Player(const char* name, int health, int level)
    : name(0), health(health), level(level)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    if (this->health < 0)
    {
        this->health = 0;
    }
    else if (this->health > 100)
    {
        this->health = 100;
    }

    if (this->level < 1)
    {
        this->level = 1;
    }

    playerCount++;
}

Player::Player() : Player("Unknown", 100, 1) {}

Player::~Player()
{
    delete[] name;
    playerCount--;
}

const char* Player::getName() const
{
    return name;
}

int Player::getHealth() const
{
    return health;
}

int Player::getLevel() const
{
    return level;
}

void Player::setName(const char* name)
{
    char* newName = new char[strlen(name) + 1];
    strcpy(newName, name);

    delete[] this->name;
    this->name = newName;
}

void Player::setHealth(int health)
{
    if (health < 0)
    {
        this->health = 0;
    }
    else
    {
        this->health = health;
    }
}

void Player::takeDamage(int damage)
{
    if (damage > 0)
    {
        setHealth(health - damage);
    }
}

void Player::heal(int amount)
{
    if (amount > 0)
    {
        health = health + amount;

        if (health > 100)
        {
            health = 100;
        }
    }
}

void Player::levelUp()
{
    level++;
}

void Player::printStats() const
{
    cout << "Name: " << name << '\n';
    cout << "Health: " << health << '\n';
    cout << "Level: " << level << '\n';
}

int Player::getPlayerCount()
{
    return playerCount;
}
