#pragma once

class String
{
private:
    char* data;
    int length;

public:
    String();
    String(const char* text);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    const char* c_str() const;
};
