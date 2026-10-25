#pragma once

enum ReservoirType
{
    Sea,
    Lake,
    Pool,
    Pond,
    Other
};

class Reservoir
{
private:
    char* name;
    double width;
    double length;
    double maxDepth;
    ReservoirType type;

    static char* copyText(const char* text);

public:
    Reservoir();
    explicit Reservoir(const char* name);
    Reservoir(const char* name, double width, double length,
        double maxDepth, ReservoirType type);
    Reservoir(const Reservoir& other);
    Reservoir& operator=(const Reservoir& other);
    ~Reservoir();

    const char* getName() const;
    double getWidth() const;
    double getLength() const;
    double getMaxDepth() const;
    ReservoirType getType() const;

    void setName(const char* name);
    void setSize(double width, double length, double maxDepth);
    void setType(ReservoirType type);

    double getVolume() const;
    double getSurface() const;
    bool isSameType(const Reservoir& other) const;
    int compareSurface(const Reservoir& other) const;
    const char* getTypeName() const;
    void show() const;
};

class ReservoirList
{
private:
    Reservoir* items;
    int size;

public:
    ReservoirList();
    ~ReservoirList();

    int getSize() const;
    void add(const Reservoir& reservoir);
    bool remove(int index);
    const Reservoir* get(int index) const;
    void show() const;
    bool saveText(const char* fileName) const;
    bool saveBinary(const char* fileName) const;
};
