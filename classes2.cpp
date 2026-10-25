#include <iostream>
#include <fstream>
using namespace std;

//task1 //Клас Студент: дані, введення, виведення та аксесори.
/*class Student
{
private:
    char fullName[100];
    char birthDate[20];
    char phone[20];
    char city[50];
    char country[50];
    char school[100];
    char schoolCity[50];
    char schoolCountry[50];
    char group[20];

public:
    void input()
    {
        cout << "full name: ";
        cin.getline(fullName, 100);
        cout << "birth date: ";
        cin.getline(birthDate, 20);
        cout << "phone: ";
        cin.getline(phone, 20);
        cout << "city: ";
        cin.getline(city, 50);
        cout << "country: ";
        cin.getline(country, 50);
        cout << "school: ";
        cin.getline(school, 100);
        cout << "school city: ";
        cin.getline(schoolCity, 50);
        cout << "school country: ";
        cin.getline(schoolCountry, 50);
        cout << "group: ";
        cin.getline(group, 20);
    }

    void show()
    {
        cout << fullName << '\n' << birthDate << '\n' << phone << '\n';
        cout << city << ", " << country << '\n';
        cout << school << '\n' << schoolCity << ", " << schoolCountry << '\n';
        cout << group << '\n';
    }

    const char* getFullName() { return fullName; }
    const char* getPhone() { return phone; }
    const char* getGroup() { return group; }
};*/

class Point
{
private:
    double x;
    double y;
    double z;

public:
    void input()
    {
        cout << "x y z: ";
        cin >> x >> y >> z;
    }

    void show()
    {
        cout << "(" << x << ", " << y << ", " << z << ")\n";
    }

    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    void setX(double value) { x = value; }
    void setY(double value) { y = value; }
    void setZ(double value) { z = value; }

    bool save(const char* fileName)
    {
        ofstream file(fileName);

        if (!file.is_open())
        {
            return false;
        }

        file << x << " " << y << " " << z;
        file.close();
        return true;
    }

    bool load(const char* fileName)
    {
        ifstream file(fileName);

        if (!file.is_open())
        {
            return false;
        }

        file >> x >> y >> z;
        bool loaded = !file.fail();
        file.close();
        return loaded;
    }
};

int main()
{
    //task2 //Клас Точка: координати, аксесори, збереження у файл і завантаження.
    Point point;
    point.input();

    cout << "point: ";
    point.show();

    if (point.save("point.txt"))
    {
        cout << "saved\n";
    }
    else
    {
        cout << "save error\n";
        return 0;
    }

    Point loadedPoint;

    if (loadedPoint.load("point.txt"))
    {
        cout << "loaded: ";
        loadedPoint.show();
    }
    else
    {
        cout << "load error";
    }
}
