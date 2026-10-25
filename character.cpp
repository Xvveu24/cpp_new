#include <iostream>
#include <string>
using namespace std;

class Character
{
protected:
    string name;
    int health;
    int shield;

public:
    Character(const string& characterName)
        : name(characterName), health(100), shield(50)
    {
    }

    void takeDamage(int amount)
    {
        if (amount <= 0)
        {
            return;
        }

        int shieldDamage = (amount < shield) ? amount : shield;
        shield -= shieldDamage;
        amount -= shieldDamage;

        health -= amount;
        if (health < 0)
        {
            health = 0;
        }
    }

    void showStatus() const
    {
        cout << name << " | health: " << health
             << " | shield: " << shield << '\n';
    }
};

class Recon : public Character
{
public:
    Recon(const string& characterName) : Character(characterName)
    {
    }

    void scanArea() const
    {
        cout << name << " сканує місцевість: виявлено 2 ворогів!\n";
    }
};

class Support : public Character
{
public:
    Support(const string& characterName) : Character(characterName)
    {
    }

    void dropHeal() const
    {
        cout << name << " скинув аптечку: союзники відновлюють здоров'я!\n";
    }
};

int main()
{
    Recon recon("Alex");
    Support support("Sam");

    recon.takeDamage(70);
    support.takeDamage(30);

    recon.showStatus();
    support.showStatus();

    recon.scanArea();
    support.dropHeal();
}
