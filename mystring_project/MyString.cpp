#include "MyString.h"
#include <cstring>
#include <iostream>
#include <ostream>
#include <stdexcept>

MyString::MyString() : data(new char[1]), length(0)
{
    data[0] = '\0';
}

MyString::MyString(const char* text) : data(nullptr), length(0)
{
    if (text == nullptr)
    {
        text = "";
    }

    length = strlen(text);
    data = new char[length + 1];
    strcpy(data, text);
}

MyString::MyString(const MyString& other) : data(new char[other.length + 1]), length(other.length)
{
    const char* source = other.data == nullptr ? "" : other.data;
    strcpy(data, source);
}

MyString::MyString(MyString&& other) noexcept
    : data(other.data), length(other.length)
{
    std::cout << "[Move Constructor]\n";
    other.data = nullptr;
    other.length = 0;
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        const char* source = other.data == nullptr ? "" : other.data;
        char* newData = new char[other.length + 1];
        strcpy(newData, source);

        delete[] data;
        data = newData;
        length = other.length;
    }

    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other)
    {
        delete[] data;
        data = other.data;
        length = other.length;

        other.data = nullptr;
        other.length = 0;
    }

    std::cout << "[Move Assignment]\n";
    return *this;
}

MyString::~MyString()
{
    delete[] data;
}

std::size_t MyString::getLength() const
{
    return length;
}

const char* MyString::c_str() const
{
    return data == nullptr ? "" : data;
}

char& MyString::operator[](std::size_t index)
{
    if (index >= length)
    {
        throw std::out_of_range("MyString index is out of range");
    }

    return data[index];
}

const char& MyString::operator[](std::size_t index) const
{
    if (index >= length)
    {
        throw std::out_of_range("MyString index is out of range");
    }

    return data[index];
}

MyString operator+(const MyString& left, const MyString& right)
{
    MyString result;
    std::size_t totalLength = left.length + right.length;
    char* newData = new char[totalLength + 1];

    std::size_t pos = 0;
    for (std::size_t i = 0; i < left.length; i++)
    {
        newData[pos] = left.data[i];
        pos++;
    }

    for (std::size_t i = 0; i < right.length; i++)
    {
        newData[pos] = right.data[i];
        pos++;
    }

    newData[pos] = '\0';
    delete[] result.data;
    result.data = newData;
    result.length = totalLength;
    return result;
}

std::ostream& operator<<(std::ostream& out, const MyString& text)
{
    out << text.c_str();
    return out;
}
