#include <iostream>
#include <cstring>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}
};

class Person
{
private:
    char* id;
    char* surname;
    char* name;
    char* fatherName;
    Date birth;
    static int count;

    static char* copyText(const char* text)
    {
        char* copy = new char[strlen(text) + 1];
        strcpy(copy, text);
        return copy;
    }

public:
    Person(const char* id, const char* surname, const char* name,
        const char* fatherName, Date birth)
        : id(copyText(id)), surname(copyText(surname)), name(copyText(name)),
          fatherName(copyText(fatherName)), birth(birth)
    {
        count++;
    }

    Person() : Person("", "", "", "", Date()) {}

    ~Person()
    {
        delete[] id;
        delete[] surname;
        delete[] name;
        delete[] fatherName;
        count--;
    }

    static int getCount()
    {
        return count;
    }

    const char* getId() const { return id; }
    const char* getSurname() const { return surname; }
    const char* getName() const { return name; }
    const char* getFatherName() const { return fatherName; }
    Date getBirth() const { return birth; }

    Person& setId(const char* id)
    {
        delete[] this->id;
        this->id = copyText(id);
        return *this;
    }

    Person& setSurname(const char* surname)
    {
        delete[] this->surname;
        this->surname = copyText(surname);
        return *this;
    }

    Person& setName(const char* name)
    {
        delete[] this->name;
        this->name = copyText(name);
        return *this;
    }

    Person& setFatherName(const char* fatherName)
    {
        delete[] this->fatherName;
        this->fatherName = copyText(fatherName);
        return *this;
    }

    Person& setBirth(Date birth)
    {
        this->birth = birth;
        return *this;
    }

    void show() const
    {
        cout << "ID: " << id << '\n';
        cout << "Name: " << surname << " " << name << " " << fatherName << '\n';
        cout << "Birth: " << birth.day << "." << birth.month << "." << birth.year << '\n';
    }
};

int Person::count = 0;

int main()
{
    Person first;
    first.setId("123456")
        .setSurname("Ivanenko")
        .setName("Ivan")
        .setFatherName("Ivanovych")
        .setBirth(Date(15, 5, 2005));

    Person second("654321", "Petrenko", "Olena", "Petrovna", Date(20, 8, 2004));

    cout << "First person:\n";
    first.show();

    cout << "\nSecond person:\n";
    second.show();

    cout << "\nObjects: " << Person::getCount();
}
