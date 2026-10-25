#include "String.h"
#include <cstring>

String::String() : data(0), length(0) {}

String::String(const char* text) : data(0), length(0)
{
    if (text != 0)
    {
        length = strlen(text);
        data = new char[length + 1];
        strcpy(data, text);
    }
}

String::String(const String& other) : data(0), length(other.length)
{
    if (other.data != 0)
    {
        data = new char[length + 1];
        strcpy(data, other.data);
    }
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        char* newData = 0;

        if (other.data != 0)
        {
            newData = new char[other.length + 1];
            strcpy(newData, other.data);
        }

        delete[] data;
        data = newData;
        length = other.length;
    }

    return *this;
}

String::~String()
{
    delete[] data;
}

const char* String::c_str() const
{
    if (data == 0)
    {
        return "";
    }

    return data;
}
