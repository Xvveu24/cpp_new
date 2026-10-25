#pragma once
#include <iostream>

template <typename T>
class Array;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr);

template <typename T>
class Array
{
private:
    T* data;
    int size;
    int capacity;

public:
    Array(int capacity = 4)
        : data(0), size(0), capacity(capacity > 0 ? capacity : 1)
    {
        data = new T[this->capacity];
    }

    Array(const Array& other)
        : data(new T[other.capacity]), size(other.size), capacity(other.capacity)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            T* newData = new T[other.capacity];

            for (int i = 0; i < other.size; i++)
            {
                newData[i] = other.data[i];
            }

            delete[] data;
            data = newData;
            size = other.size;
            capacity = other.capacity;
        }

        return *this;
    }

    ~Array()
    {
        delete[] data;
    }

    void reserve(int newCapacity)
    {
        if (newCapacity <= capacity)
        {
            return;
        }

        T* newData = new T[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    void insertAt(int index, T value)
    {
        if (index < 0 || index > size)
        {
            std::cerr << "Invalid index\n";
            return;
        }

        if (size == capacity)
        {
            reserve(capacity * 2);
        }

        for (int i = size; i > index; i--)
        {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size++;
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cerr << "Invalid index\n";
            return;
        }

        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;
    }

    void pushFront(T value)
    {
        if (size == capacity)
        {
            reserve(capacity * 2);
        }

        for (int i = size; i > 0; i--)
        {
            data[i] = data[i - 1];
        }

        data[0] = value;
        size++;
    }

    void popFront()
    {
        if (empty())
        {
            return;
        }

        for (int i = 0; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;
    }

    void clear()
    {
        size = 0;
    }

    bool empty() const
    {
        return size == 0;
    }

    int getSize() const
    {
        return size;
    }

    friend std::ostream& operator<< <T>(std::ostream& out, const Array<T>& arr);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr)
{
    if (arr.empty())
    {
        out << "{}";
        return out;
    }

    out << "{ ";

    for (int i = 0; i < arr.size; i++)
    {
        out << arr.data[i];

        if (i < arr.size - 1)
        {
            out << ", ";
        }
    }

    out << " }";
    return out;
}
