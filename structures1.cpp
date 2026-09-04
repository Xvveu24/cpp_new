#include <iostream>
#include <cstring>
using namespace std;

//task1 //Завдання 1 Структура комплексного числа. Сума, різниця, множення, ділення.
/*struct Complex
{
    double real;
    double imag;
};

Complex add(Complex a, Complex b)
{
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

Complex sub(Complex a, Complex b)
{
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

Complex mult(Complex a, Complex b)
{
    Complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

Complex divi(Complex a, Complex b)
{
    Complex c;
    double d = b.real * b.real + b.imag * b.imag;
    c.real = (a.real * b.real + a.imag * b.imag) / d;
    c.imag = (a.imag * b.real - a.real * b.imag) / d;
    return c;
}*/

//task2 //Завдання 2 Структура "Автомобіль". Введення, друк, пошук.
/*struct Auto
{
    double length;
    double clearance;
    double engine;
    int power;
    double wheels;
    char color[20];
    char transmission[20];
};

void inputAuto(Auto& car)
{
    cout << "length: ";
    cin >> car.length;
    cout << "clearance: ";
    cin >> car.clearance;
    cout << "engine: ";
    cin >> car.engine;
    cout << "power: ";
    cin >> car.power;
    cout << "wheels: ";
    cin >> car.wheels;
    cout << "color: ";
    cin >> car.color;
    cout << "transmission: ";
    cin >> car.transmission;
}

void showAuto(Auto car)
{
    cout << car.length << " " << car.clearance << " " << car.engine << " ";
    cout << car.power << " " << car.wheels << " " << car.color << " " << car.transmission;
}*/

//task3 //Завдання 3 Програма "Бібліотека". Масив книг, редагування, друк, пошук, сортування.
/*struct Book
{
    char title[50];
    char author[50];
    char publisher[50];
    char genre[30];
};

void showBook(Book book)
{
    cout << book.title << " " << book.author << " " << book.publisher << " " << book.genre << '\n';
}

void inputBook(Book& book)
{
    cout << "title: ";
    cin >> book.title;
    cout << "author: ";
    cin >> book.author;
    cout << "publisher: ";
    cin >> book.publisher;
    cout << "genre: ";
    cin >> book.genre;
}*/

//task4 //Завдання 4 Структура "Машина". Введення, друк, редагування, список, пошук за номером.
/*struct Car
{
    char color[20];
    char model[30];
    char number[9];
};

void inputCar(Car& car)
{
    cout << "color: ";
    cin >> car.color;
    cout << "model: ";
    cin >> car.model;
    cout << "number: ";
    cin >> car.number;
}

void showCar(Car car)
{
    cout << car.color << " " << car.model << " " << car.number << '\n';
}*/

//task5 //Завдання 5 Структура "Жива сутність". Введення, друк, редагування, список, пошук.
/*struct Creature
{
    double speed;
    char type[20];
    char color[20];
    double flySpeed;
    bool hoofed;
    int iq;
};

void inputCreature(Creature& c)
{
    cout << "speed: ";
    cin >> c.speed;
    cout << "type: ";
    cin >> c.type;
    cout << "color: ";
    cin >> c.color;

    if (strcmp(c.type, "bird") == 0)
    {
        cout << "fly speed: ";
        cin >> c.flySpeed;
    }
    else if (strcmp(c.type, "cattle") == 0)
    {
        cout << "hoofed 1/0: ";
        cin >> c.hoofed;
    }
    else if (strcmp(c.type, "human") == 0)
    {
        cout << "iq: ";
        cin >> c.iq;
    }
}

void showCreature(Creature c)
{
    cout << c.speed << " " << c.type << " " << c.color << " ";

    if (strcmp(c.type, "bird") == 0)
    {
        cout << c.flySpeed;
    }
    else if (strcmp(c.type, "cattle") == 0)
    {
        cout << c.hoofed;
    }
    else if (strcmp(c.type, "human") == 0)
    {
        cout << c.iq;
    }

    cout << '\n';
}*/

//task6 //Завдання 6 Структура Student. Зміна розміру масиву, відмінники, двієчники.
/*struct Student
{
    char surname[30];
    char group[20];
    int marks[5];
};

void inputStudent(Student& st)
{
    cout << "surname: ";
    cin >> st.surname;
    cout << "group: ";
    cin >> st.group;

    for (int i = 0; i < 5; i++)
    {
        cout << "mark: ";
        cin >> st.marks[i];
    }
}

void showStudent(Student st)
{
    cout << st.surname << " " << st.group << '\n';
}*/

struct Date
{
    int day;
    int month;
    int year;
};

struct Man
{
    char surname[30];
    char name[30];
    int age;
    Date birth;
};

void inputMan(Man& man)
{
    cout << "surname: ";
    cin >> man.surname;
    cout << "name: ";
    cin >> man.name;
    cout << "age: ";
    cin >> man.age;
    cout << "date: ";
    cin >> man.birth.day >> man.birth.month >> man.birth.year;
}

void showMan(Man man)
{
    cout << man.surname << " " << man.name << " " << man.age << " ";
    cout << man.birth.day << "." << man.birth.month << "." << man.birth.year << '\n';
}

Man* addMan(Man* people, int& size)
{
    Man* temp = new Man[size + 1];

    for (int i = 0; i < size; i++)
    {
        temp[i] = people[i];
    }

    inputMan(temp[size]);

    delete[] people;
    size++;

    return temp;
}

Man* deleteMan(Man* people, int& size, int index)
{
    if (index < 0 || index >= size)
    {
        return people;
    }

    Man* temp = new Man[size - 1];
    int pos = 0;

    for (int i = 0; i < size; i++)
    {
        if (i != index)
        {
            temp[pos] = people[i];
            pos++;
        }
    }

    delete[] people;
    size--;

    return temp;
}

void sortBySurname(Man* people, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(people[j].surname, people[j + 1].surname) > 0)
            {
                Man temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

void sortByName(Man* people, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(people[j].name, people[j + 1].name) > 0)
            {
                Man temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main()
{
    //task7 //Завдання 7 Структура Man. Сортування, іменинники місяця, зміна розміру, пошук, редагування.
    Man* people = 0;
    int size = 0;
    int choice;

    do
    {
        cout << "\n1-add\n";
        cout << "2-delete\n";
        cout << "3-show surname\n";
        cout << "4-show name\n";
        cout << "5-birthday\n";
        cout << "6-find\n";
        cout << "7-edit\n";
        cout << "0-exit\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 1)
        {
            people = addMan(people, size);
        }
        else if (choice == 2)
        {
            int index;
            cout << "number: ";
            cin >> index;

            people = deleteMan(people, size, index - 1);
        }
        else if (choice == 3)
        {
            sortBySurname(people, size);

            for (int i = 0; i < size; i++)
            {
                showMan(people[i]);
            }
        }
        else if (choice == 4)
        {
            sortByName(people, size);

            for (int i = 0; i < size; i++)
            {
                showMan(people[i]);
            }
        }
        else if (choice == 5)
        {
            int month;
            cout << "month: ";
            cin >> month;

            for (int i = 0; i < size; i++)
            {
                if (people[i].birth.month == month)
                {
                    showMan(people[i]);
                }
            }
        }
        else if (choice == 6)
        {
            char text[30];
            cout << "text: ";
            cin >> text;

            for (int i = 0; i < size; i++)
            {
                if (strcmp(people[i].surname, text) == 0 || strcmp(people[i].name, text) == 0)
                {
                    showMan(people[i]);
                }
            }
        }
        else if (choice == 7)
        {
            int index;
            cout << "number: ";
            cin >> index;

            if (index >= 1 && index <= size)
            {
                inputMan(people[index - 1]);
            }
        }
    } while (choice != 0);

    delete[] people;

}
