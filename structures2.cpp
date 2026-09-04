#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

//task1 //Завдання 1 Структура точки. Функція обчислює відстань між двома точками.
/*struct Point
{
    double x;
    double y;
};

double distance(Point a, Point b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}*/

//task2 //Завдання 2 Структура простого дробу. Сума, різниця, множення, ділення, скорочення.
/*struct Fraction
{
    int num;
    int den;
};

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void reduce(Fraction& f)
{
    int d = gcd(abs(f.num), abs(f.den));
    f.num = f.num / d;
    f.den = f.den / d;

    if (f.den < 0)
    {
        f.num = -f.num;
        f.den = -f.den;
    }
}

Fraction add(Fraction a, Fraction b)
{
    Fraction c;
    c.num = a.num * b.den + b.num * a.den;
    c.den = a.den * b.den;
    reduce(c);
    return c;
}

Fraction sub(Fraction a, Fraction b)
{
    Fraction c;
    c.num = a.num * b.den - b.num * a.den;
    c.den = a.den * b.den;
    reduce(c);
    return c;
}

Fraction mult(Fraction a, Fraction b)
{
    Fraction c;
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    reduce(c);
    return c;
}

Fraction divi(Fraction a, Fraction b)
{
    Fraction c;
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    reduce(c);
    return c;
}*/

//task3 //Завдання 3 Структура "Пральна машина". Створити екземпляр і показати роботу.
/*struct Washer
{
    char firm[30];
    char color[20];
    double width;
    double length;
    double height;
    int power;
    int spinSpeed;
    int temp;
};

int main()
{
    Washer w = { "Samsung", "white", 60, 55, 85, 2000, 1200, 90 };

    cout << w.firm << " " << w.color << " " << w.width << " ";
    cout << w.length << " " << w.height << " " << w.power << " ";
    cout << w.spinSpeed << " " << w.temp;
}*/

//task4 //Завдання 4 Структура тварини. Заповнення, друк, подати голос.
/*struct Animal
{
    char name[30];
    char type[30];
    char nickname[30];
};

void inputAnimal(Animal& a)
{
    cout << "name: ";
    cin >> a.name;
    cout << "type: ";
    cin >> a.type;
    cout << "nick: ";
    cin >> a.nickname;
}

void showAnimal(Animal a)
{
    cout << a.name << " " << a.type << " " << a.nickname << '\n';
}

void voice(Animal a)
{
    if (strcmp(a.type, "dog") == 0)
    {
        cout << "woof";
    }
    else if (strcmp(a.type, "cat") == 0)
    {
        cout << "meow";
    }
    else
    {
        cout << "some sound";
    }
}*/

//task5 //Завдання 5 Об'єднання для 4-байтової змінної як signed і unsigned int.
/*union Number
{
    int signedNumber;
    unsigned int unsignedNumber;
};

int main()
{
    Number n;

    cout << "number: ";
    cin >> n.signedNumber;

    cout << "signed: " << n.signedNumber << '\n';
    cout << "unsigned: " << n.unsignedNumber;
}*/

struct Student
{
    char surname[30];
    char name[30];
    char father[30];

    unsigned int m1 : 1;
    unsigned int m2 : 1;
    unsigned int m3 : 1;
    unsigned int m4 : 1;
    unsigned int m5 : 1;
    unsigned int m6 : 1;
    unsigned int m7 : 1;
    unsigned int m8 : 1;
    unsigned int m9 : 1;
    unsigned int m10 : 1;
};

void inputStudent(Student& st)
{
    cout << "surname: ";
    cin >> st.surname;
    cout << "name: ";
    cin >> st.name;
    cout << "father: ";
    cin >> st.father;

    st.m1 = st.m2 = st.m3 = st.m4 = st.m5 = 0;
    st.m6 = st.m7 = st.m8 = st.m9 = st.m10 = 0;
}

void setMarks(Student& st)
{
    int mark;

    cout << "10 marks 1/0:\n";
    cin >> mark;
    st.m1 = mark;
    cin >> mark;
    st.m2 = mark;
    cin >> mark;
    st.m3 = mark;
    cin >> mark;
    st.m4 = mark;
    cin >> mark;
    st.m5 = mark;
    cin >> mark;
    st.m6 = mark;
    cin >> mark;
    st.m7 = mark;
    cin >> mark;
    st.m8 = mark;
    cin >> mark;
    st.m9 = mark;
    cin >> mark;
    st.m10 = mark;
}

int passedCount(Student st)
{
    return st.m1 + st.m2 + st.m3 + st.m4 + st.m5 + st.m6 + st.m7 + st.m8 + st.m9 + st.m10;
}

void showStudent(Student st)
{
    cout << st.surname << " " << st.name << " " << st.father << '\n';
}

void showMarks(Student st)
{
    cout << st.m1 << " " << st.m2 << " " << st.m3 << " " << st.m4 << " " << st.m5 << " ";
    cout << st.m6 << " " << st.m7 << " " << st.m8 << " " << st.m9 << " " << st.m10 << '\n';
}

Student* addStudent(Student* students, int& size)
{
    Student* temp = new Student[size + 1];

    for (int i = 0; i < size; i++)
    {
        temp[i] = students[i];
    }

    inputStudent(temp[size]);

    delete[] students;
    size++;

    return temp;
}

int main()
{
    //task6 //Завдання 6 Структура студент з 10 бітовими полями. Додати, оцінки, список, оцінки студента, боржники.
    Student* students = 0;
    int size = 0;
    int choice;

    do
    {
        cout << "\n1-add\n";
        cout << "2-marks\n";
        cout << "3-list\n";
        cout << "4-show marks\n";
        cout << "5-debtors\n";
        cout << "0-exit\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 1)
        {
            students = addStudent(students, size);
        }
        else if (choice == 2)
        {
            int index;
            cout << "number: ";
            cin >> index;

            if (index >= 1 && index <= size)
            {
                setMarks(students[index - 1]);
            }
        }
        else if (choice == 3)
        {
            for (int i = 0; i < size; i++)
            {
                cout << i + 1 << ". ";
                showStudent(students[i]);
            }
        }
        else if (choice == 4)
        {
            int index;
            cout << "number: ";
            cin >> index;

            if (index >= 1 && index <= size)
            {
                showMarks(students[index - 1]);
            }
        }
        else if (choice == 5)
        {
            for (int i = 0; i < size; i++)
            {
                if (passedCount(students[i]) < 10)
                {
                    showStudent(students[i]);
                }
            }
        }
    } while (choice != 0);

    delete[] students;

}
