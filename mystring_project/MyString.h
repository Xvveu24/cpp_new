#pragma once
#include <cstddef>
#include <iosfwd>

class MyString
{
private:
    char* data;
    std::size_t length;

public:
    MyString();
    MyString(const char* text);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;
    ~MyString();

    std::size_t getLength() const;
    const char* c_str() const;

    char& operator[](std::size_t index);
    const char& operator[](std::size_t index) const;

    friend MyString operator+(const MyString& left, const MyString& right);
    friend std::ostream& operator<<(std::ostream& out, const MyString& text);
};
