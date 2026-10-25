#include <iostream>
using namespace std;

class IHackable
{
public:
    virtual void applyHack(int techLevel) = 0;
    virtual bool isHacked() const = 0;
    virtual ~IHackable() = default;
};

class VendingMachine : public IHackable
{
private:
    bool hacked;

public:
    VendingMachine() : hacked(false)
    {
    }

    void applyHack(int techLevel) override
    {
        if (techLevel >= 2)
        {
            hacked = true;
            cout << "Vending machine hacked! All drinks fall out.\n";
        }
        else
        {
            cout << "The vending machine shocks the hacker!\n";
        }
    }

    bool isHacked() const override
    {
        return hacked;
    }
};

class SmartDoor : public IHackable
{
private:
    bool opened;

public:
    SmartDoor() : opened(false)
    {
    }

    void applyHack(int techLevel) override
    {
        if (techLevel >= 5)
        {
            opened = true;
            cout << "Smart door opened.\n";
        }
        else
        {
            cout << "Hack failed. The smart door stays closed.\n";
        }
    }

    bool isHacked() const override
    {
        return opened;
    }
};

class CyberEnemy
{
protected:
    int health;

public:
    explicit CyberEnemy(int enemyHealth) : health(enemyHealth)
    {
    }

    virtual void attack() const = 0;
    virtual ~CyberEnemy() = default;
};

class CyborgGuard : public CyberEnemy, public IHackable
{
private:
    bool frozen;

public:
    CyborgGuard() : CyberEnemy(100), frozen(false)
    {
    }

    void applyHack(int techLevel) override
    {
        if (techLevel >= 7)
        {
            frozen = true;
            cout << "Cyborg guard is frozen and temporarily disabled.\n";
        }
        else
        {
            health -= 20;
            if (health < 0)
            {
                health = 0;
            }
            cout << "Virus damaged the cyborg. Health: " << health << '\n';
        }
    }

    bool isHacked() const override
    {
        return frozen;
    }

    void attack() const override
    {
        if (frozen)
        {
            cout << "Cyborg guard cannot attack while frozen.\n";
        }
        else
        {
            cout << "Cyborg guard attacks the player.\n";
        }
    }
};

class AutoTurret : public CyberEnemy, public IHackable
{
private:
    bool hacked;

public:
    AutoTurret() : CyberEnemy(80), hacked(false)
    {
    }

    void applyHack(int techLevel) override
    {
        if (techLevel >= 4)
        {
            hacked = true;
            cout << "Turret hacked! It now targets other enemies.\n";
        }
        else
        {
            cout << "Turret hack failed.\n";
        }
    }

    bool isHacked() const override
    {
        return hacked;
    }

    void attack() const override
    {
        if (hacked)
        {
            cout << "Turret attacks other enemies.\n";
        }
        else
        {
            cout << "Turret attacks the player.\n";
        }
    }
};

class Netrunner
{
private:
    int skillLevel;

public:
    explicit Netrunner(int level) : skillLevel(level)
    {
    }

    void breachProtocol(IHackable& target)
    {
        target.applyHack(this->skillLevel);
    }
};

int main()
{
    Netrunner hacker(5);
    SmartDoor door;
    VendingMachine vendingMachine;
    CyborgGuard cyborg;

    hacker.breachProtocol(door);
    hacker.breachProtocol(vendingMachine);
    hacker.breachProtocol(cyborg);

    cout << "Door hacked: " << (door.isHacked() ? "yes" : "no") << '\n';
    cout << "Vending machine hacked: "
         << (vendingMachine.isHacked() ? "yes" : "no") << '\n';
    cout << "Cyborg disabled: " << (cyborg.isHacked() ? "yes" : "no") << '\n';
    cyborg.attack();
}
