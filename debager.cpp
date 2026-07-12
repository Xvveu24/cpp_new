#include <iostream>
using namespace std;

int main()
{
    //task1 //Завдання 1 Напишіть програму, яка обчислює суму цілих чисел від а до 500.
    /*int a;
    int sum = 0;

    cout << "enter a: ";
    cin >> a;

    for (int i = a; i <= 500; i++)
    {
        sum = sum + i;
    }

    cout << "sum: " << sum;*/

    //task2 //Завдання 2 Напишіть програму, яка запитує два цілих числа x і y, після чого обчислює і виводить значення x у степені y.
    /*int x, y;
    int result = 1;

    cout << "enter x: ";
    cin >> x;
    cout << "enter y: ";
    cin >> y;

    for (int i = 1; i <= y; i++)
    {
        result = result * x;
    }

    cout << "result: " << result;*/

    //task3 //Завдання 3 Знайти середнє арифметичне всіх цілих чисел від 1 до 1000.
    /*int sum = 0;

    for (int i = 1; i <= 1000; i++)
    {
        sum = sum + i;
    }

    double average = sum / 1000.0;

    cout << "average: " << average;*/

    //task4 //Завдання 4 Знайти добуток усіх цілих чисел від a до 20.
    /*int a;
    long long mult = 1;

    cout << "enter a from 1 to 20: ";
    cin >> a;

    if (a >= 1 && a <= 20)
    {
        for (int i = a; i <= 20; i++)
        {
            mult = mult * i;
        }

        cout << "multiplication: " << mult;
    }
    else
    {
        cout << "wrong a";
    }*/

    //task5 //Завдання 5 Написати програму, яка виводить на екран таблицю множення на k.
    /*int k;

    cout << "enter k: ";
    cin >> k;

    for (int i = 1; i <= 10; i++)
    {
        cout << k << " * " << i << " = " << k * i << '\n';
    }*/

    //task6 //Завдання 6 Користувач вводить довільне ціле число А. Вивести всі цілі числа В, для яких А ділиться на В*В і не ділиться на В*В*В.
    /*int a;

    cout << "enter A: ";
    cin >> a;

    for (int b = 1; b <= a; b++)
    {
        if (a % (b * b) == 0 && a % (b * b * b) != 0)
        {
            cout << b << " ";
        }
    }*/

    //task7 //Завдання 7 Користувач вводить ціле число. Необхідно вивести всі цілі числа, на які задане число ділиться без залишку.
    /*int number;

    cout << "enter number: ";
    cin >> number;

    for (int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            cout << i << " ";
        }
    }*/

    //task8 //Завдання 8 Користувач вводить два цілих числа. Вивести всі цілі числа, на які обидва введених числа діляться без залишку.
    /*int a, b;
    int minNumber;

    cout << "enter first number: ";
    cin >> a;
    cout << "enter second number: ";
    cin >> b;

    if (a < b)
    {
        minNumber = a;
    }
    else
    {
        minNumber = b;
    }

    for (int i = 1; i <= minNumber; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            cout << i << " ";
        }
    }*/

    //task9 //Завдання 9 Вивести на екран фігури заповнені символом. Користувач вводить символ, обирає фігуру: квадрат, прямокутник, трикутник.
    char symbol;
    int choice;

    cout << "enter symbol: ";
    cin >> symbol;

    cout << "1 - square\n";
    cout << "2 - rectangle\n";
    cout << "3 - triangle\n";
    cout << "enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int side;

        cout << "enter side: ";
        cin >> side;

        for (int i = 1; i <= side; i++)
        {
            for (int j = 1; j <= side; j++)
            {
                cout << symbol;
            }
            cout << '\n';
        }
    }
    else if (choice == 2)
    {
        int width, height;

        cout << "enter width: ";
        cin >> width;
        cout << "enter height: ";
        cin >> height;

        for (int i = 1; i <= height; i++)
        {
            for (int j = 1; j <= width; j++)
            {
                cout << symbol;
            }
            cout << '\n';
        }
    }
    else if (choice == 3)
    {
        int height;

        cout << "enter height: ";
        cin >> height;

        for (int i = 1; i <= height; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << symbol;
            }
            cout << '\n';
        }
    }
    else
    {
        cout << "wrong choice";
    }

}
