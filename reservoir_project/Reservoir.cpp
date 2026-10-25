#include "Reservoir.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char* Reservoir::copyText(const char* text)
{
    if (text == 0)
    {
        text = "";
    }

    char* result = new char[strlen(text) + 1];
    strcpy(result, text);
    return result;
}

Reservoir::Reservoir()
    : name(copyText("")), width(0), length(0), maxDepth(0), type(Other) {}

Reservoir::Reservoir(const char* name)
    : name(copyText(name)), width(0), length(0), maxDepth(0), type(Other) {}

Reservoir::Reservoir(const char* name, double width, double length,
    double maxDepth, ReservoirType type)
    : name(copyText(name)), width(width), length(length), maxDepth(maxDepth), type(type) {}

Reservoir::Reservoir(const Reservoir& other)
    : name(copyText(other.name)), width(other.width), length(other.length),
      maxDepth(other.maxDepth), type(other.type) {}

Reservoir& Reservoir::operator=(const Reservoir& other)
{
    if (this != &other)
    {
        char* newName = copyText(other.name);
        delete[] name;
        name = newName;
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
        type = other.type;
    }

    return *this;
}

Reservoir::~Reservoir()
{
    delete[] name;
}

const char* Reservoir::getName() const { return name; }
double Reservoir::getWidth() const { return width; }
double Reservoir::getLength() const { return length; }
double Reservoir::getMaxDepth() const { return maxDepth; }
ReservoirType Reservoir::getType() const { return type; }

void Reservoir::setName(const char* name)
{
    char* newName = copyText(name);
    delete[] this->name;
    this->name = newName;
}

void Reservoir::setSize(double width, double length, double maxDepth)
{
    this->width = width;
    this->length = length;
    this->maxDepth = maxDepth;
}

void Reservoir::setType(ReservoirType type)
{
    this->type = type;
}

double Reservoir::getVolume() const
{
    return width * length * maxDepth;
}

double Reservoir::getSurface() const
{
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const
{
    if (type == other.type)
    {
        return true;
    }

    bool thisArtificial = type == Pool || type == Pond;
    bool otherArtificial = other.type == Pool || other.type == Pond;

    return thisArtificial && otherArtificial;
}

int Reservoir::compareSurface(const Reservoir& other) const
{
    if (!isSameType(other))
    {
        return 2;
    }

    if (getSurface() > other.getSurface())
    {
        return 1;
    }
    if (getSurface() < other.getSurface())
    {
        return -1;
    }

    return 0;
}

const char* Reservoir::getTypeName() const
{
    switch (type)
    {
    case Sea: return "Sea";
    case Lake: return "Lake";
    case Pool: return "Pool";
    case Pond: return "Pond";
    default: return "Other";
    }
}

void Reservoir::show() const
{
    cout << "Name: " << name << '\n';
    cout << "Type: " << getTypeName() << '\n';
    cout << "Width: " << width << '\n';
    cout << "Length: " << length << '\n';
    cout << "Max depth: " << maxDepth << '\n';
    cout << "Surface: " << getSurface() << '\n';
    cout << "Volume: " << getVolume() << '\n';
}

ReservoirList::ReservoirList() : items(0), size(0) {}

ReservoirList::~ReservoirList()
{
    delete[] items;
}

int ReservoirList::getSize() const { return size; }

void ReservoirList::add(const Reservoir& reservoir)
{
    Reservoir* temp = new Reservoir[size + 1];

    for (int i = 0; i < size; i++)
    {
        temp[i] = items[i];
    }

    temp[size] = reservoir;
    delete[] items;
    items = temp;
    size++;
}

bool ReservoirList::remove(int index)
{
    if (index < 0 || index >= size)
    {
        return false;
    }

    Reservoir* temp = 0;

    if (size > 1)
    {
        temp = new Reservoir[size - 1];
        int pos = 0;

        for (int i = 0; i < size; i++)
        {
            if (i != index)
            {
                temp[pos] = items[i];
                pos++;
            }
        }
    }

    delete[] items;
    items = temp;
    size--;
    return true;
}

const Reservoir* ReservoirList::get(int index) const
{
    if (index < 0 || index >= size)
    {
        return 0;
    }

    return &items[index];
}

void ReservoirList::show() const
{
    if (size == 0)
    {
        cout << "list is empty\n";
    }

    for (int i = 0; i < size; i++)
    {
        cout << "\n" << i + 1 << ".\n";
        items[i].show();
    }
}

bool ReservoirList::saveText(const char* fileName) const
{
    ofstream file(fileName);

    if (!file.is_open())
    {
        return false;
    }

    file << size << '\n';

    for (int i = 0; i < size; i++)
    {
        file << items[i].getName() << '\n';
        file << (int)items[i].getType() << '\n';
        file << items[i].getWidth() << '\n';
        file << items[i].getLength() << '\n';
        file << items[i].getMaxDepth() << '\n';
    }

    file.close();
    return true;
}

bool ReservoirList::saveBinary(const char* fileName) const
{
    ofstream file(fileName, ios::binary);

    if (!file.is_open())
    {
        return false;
    }

    file.write((char*)&size, sizeof(size));

    for (int i = 0; i < size; i++)
    {
        int nameLength = strlen(items[i].getName());
        int type = (int)items[i].getType();
        double width = items[i].getWidth();
        double length = items[i].getLength();
        double maxDepth = items[i].getMaxDepth();

        file.write((char*)&nameLength, sizeof(nameLength));
        file.write(items[i].getName(), nameLength);
        file.write((char*)&type, sizeof(type));
        file.write((char*)&width, sizeof(width));
        file.write((char*)&length, sizeof(length));
        file.write((char*)&maxDepth, sizeof(maxDepth));
    }

    file.close();
    return true;
}
