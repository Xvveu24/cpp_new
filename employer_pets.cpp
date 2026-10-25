#include <iostream>
#include <string>
using namespace std;

/*
// Завдання 1
class Pet
{
protected:
    string name;
    string characteristic;

public:
    Pet(const string& petName, const string& petCharacteristic)
        : name(petName), characteristic(petCharacteristic)
    {
    }

    virtual void Sound() const = 0;

    void Show() const
    {
        cout << "Name: " << name << '\n';
    }

    virtual void Type() const = 0;
    virtual ~Pet() = default;
};

class Dog : public Pet
{
public:
    Dog(const string& name, const string& characteristic)
        : Pet(name, characteristic) {}

    void Sound() const override { cout << "Woof!\n"; }
    void Type() const override
    {
        cout << "Type: Dog, " << characteristic << '\n';
    }
};

class Cat : public Pet
{
public:
    Cat(const string& name, const string& characteristic)
        : Pet(name, characteristic) {}

    void Sound() const override { cout << "Meow!\n"; }
    void Type() const override
    {
        cout << "Type: Cat, " << characteristic << '\n';
    }
};

class Parrot : public Pet
{
public:
    Parrot(const string& name, const string& characteristic)
        : Pet(name, characteristic) {}

    void Sound() const override { cout << "Squawk!\n"; }
    void Type() const override
    {
        cout << "Type: Parrot, " << characteristic << '\n';
    }
};

class Hamster : public Pet
{
public:
    Hamster(const string& name, const string& characteristic)
        : Pet(name, characteristic) {}

    void Sound() const override { cout << "Squeak!\n"; }
    void Type() const override
    {
        cout << "Type: Hamster, " << characteristic << '\n';
    }
};
*/

// Завдання 2
class Employer
{
public:
    virtual void Print() const = 0;
    virtual ~Employer() = default;
};

class President : public Employer
{
public:
    void Print() const override
    {
        cout << "President: manages the company.\n";
    }
};

class Manager : public Employer
{
public:
    void Print() const override
    {
        cout << "Manager: manages a team.\n";
    }
};

class Worker : public Employer
{
public:
    void Print() const override
    {
        cout << "Worker: performs assigned tasks.\n";
    }
};

int main()
{
    President president;
    Manager manager;
    Worker worker;

    Employer* employees[] = { &president, &manager, &worker };

    for (Employer* employee : employees)
    {
        employee->Print();
    }
}
