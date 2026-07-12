#include <iostream>
using namespace std;

int main()
{
    //task1 //Завдання 1 Користувач вводить число. Визначити, чи є воно парним.
    /*int number;
    cout << "enter number: ";
    cin >> number;

    if (number % 2 == 0)
    {
        cout << "number is even";
    }
    else
    {
        cout << "number is odd";
    }*/

    //task2 //Завдання 2 Користувач вводить два числа. Вивести на екран менше з цих чисел.
    /*int a, b;
    cout << "enter first number: ";
    cin >> a;
    cout << "enter second number: ";
    cin >> b;

    if (a < b)
    {
        cout << "smaller number: " << a;
    }
    else
    {
        cout << "smaller number: " << b;
    }*/

    //task3 //Завдання 3 Користувач вводить число. Визначити додатне це число, від'ємне чи дорівнює нулю.
    /*int number;
    cout << "enter number: ";
    cin >> number;

    if (number > 0)
    {
        cout << "number is positive";
    }
    else if (number < 0)
    {
        cout << "number is negative";
    }
    else
    {
        cout << "number is zero";
    }*/

    //task4 //Завдання 4 Користувач вводить два числа. Визначити, чи рівні ці числа, і якщо ні, вивести їх на екран у порядку зростання.
    /*int a, b;
    cout << "enter first number: ";
    cin >> a;
    cout << "enter second number: ";
    cin >> b;

    if (a == b)
    {
        cout << "numbers are equal";
    }
    else if (a < b)
    {
        cout << a << " " << b;
    }
    else
    {
        cout << b << " " << a;
    }*/

    //task5 //Завдання 5 Користувач із клавіатури вводить 5 оцінок студента. Визначити, чи допущено студента до іспиту. Студент отримує допуск, якщо його середній бал 4 бали і вище.
    /*int m1, m2, m3, m4, m5;
    cout << "enter first mark: ";
    cin >> m1;
    cout << "enter second mark: ";
    cin >> m2;
    cout << "enter third mark: ";
    cin >> m3;
    cout << "enter fourth mark: ";
    cin >> m4;
    cout << "enter fifth mark: ";
    cin >> m5;

    double average = (m1 + m2 + m3 + m4 + m5) / 5.0;

    cout << "average: " << average << '\n';

    if (average >= 4)
    {
        cout << "student is allowed to exam";
    }
    else
    {
        cout << "student is not allowed to exam";
    }*/

    //task6 //Завдання 6 Користувач вводить із клавіатури число. Якщо воно парне, помножити його на три, інакше - поділити на два. Результат вивести на екран.
    /*double number;
    cout << "enter number: ";
    cin >> number;

    if ((int)number % 2 == 0)
    {
        number = number * 3;
    }
    else
    {
        number = number / 2;
    }

    cout << "result: " << number;*/

    //task7 //Завдання 7 Написати програму-калькулятор. Користувач вводить два числа і вибирає арифметичну дію. Вивести на екран результат.
    /*double a, b;
    char action;

    cout << "enter first number: ";
    cin >> a;
    cout << "enter second number: ";
    cin >> b;
    cout << "enter action (+, -, *, /): ";
    cin >> action;

    if (action == '+')
    {
        cout << "result: " << a + b;
    }
    else if (action == '-')
    {
        cout << "result: " << a - b;
    }
    else if (action == '*')
    {
        cout << "result: " << a * b;
    }
    else if (action == '/')
    {
        if (b == 0)
        {
            cout << "can not divide by zero";
        }
        else
        {
            cout << "result: " << a / b;
        }
    }
    else
    {
        cout << "wrong action";
    }

    //task8 //Завдання 8 Написати програму, яка за вибором користувача зводить введене ним число в ступінь від нульового до сьомого включно.
    double number;
    int power;

    cout << "enter number: ";
    cin >> number;
    cout << "enter power from 0 to 7: ";
    cin >> power;

    double result = 1;

    if (power >= 0 && power <= 7)
    {
        for (int i = 1; i <= power; i++)
        {
            result = result * number;
        }

        cout << "result: " << result;
    }
    else
    {
        cout << "wrong power";
    }

}
