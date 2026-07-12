#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //task1 //Завдання 1 Вивести на екран усі числа від нуля до введеного користувачем числа включно.
    /*int number;

    cout << "enter number: ";
    cin >> number;

    for (int i = 0; i <= number; i++)
    {
        cout << i << " ";
    }*/

    //task2 //Завдання 2 Користувач вводить дві межі діапазону. Вивести всі числа, парні, непарні та кратні семи.
    /*int a, b;
    int start, end;

    cout << "enter first border: ";
    cin >> a;
    cout << "enter second border: ";
    cin >> b;

    if (a < b)
    {
        start = a;
        end = b;
    }
    else
    {
        start = b;
        end = a;
    }

    cout << "all numbers:\n";
    for (int i = start; i <= end; i++)
    {
        cout << i << " ";
    }

    cout << "\neven numbers:\n";
    for (int i = start; i <= end; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
    }

    cout << "\nodd numbers:\n";
    for (int i = start; i <= end; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << " ";
        }
    }

    cout << "\nnumbers divisible by 7:\n";
    for (int i = start; i <= end; i++)
    {
        if (i % 7 == 0)
        {
            cout << i << " ";
        }
    }*/

    //task3 //Завдання 3 Користувач вводить дві межі діапазону. Порахувати суму всіх чисел діапазону.
    /*int a, b;
    int start, end;
    int sum = 0;

    cout << "enter first border: ";
    cin >> a;
    cout << "enter second border: ";
    cin >> b;

    if (a < b)
    {
        start = a;
        end = b;
    }
    else
    {
        start = b;
        end = a;
    }

    for (int i = start; i <= end; i++)
    {
        sum = sum + i;
    }

    cout << "sum: " << sum;*/

    //task4 //Завдання 4 Користувач із клавіатури вводить числа. Якщо користувач введе 0 - вивести суму цих чисел.
    /*int number;
    int sum = 0;

    cout << "enter numbers, 0 to stop:\n";

    do
    {
        cin >> number;
        sum = sum + number;
    } while (number != 0);

    cout << "sum: " << sum;*/

    //task5 //Завдання 5 Написати гру "Вгадай число" від 1 до 500. Вихід якщо користувач ввів 0.
    /*srand(time(0));

    int secret = rand() % 500 + 1;
    int userNumber;
    int tries = 0;

    cout << "guess number from 1 to 500, enter 0 to exit\n";

    do
    {
        cout << "enter number: ";
        cin >> userNumber;

        if (userNumber == 0)
        {
            cout << "game over";
        }
        else
        {
            tries++;

            if (userNumber < secret)
            {
                cout << "secret number is bigger\n";
            }
            else if (userNumber > secret)
            {
                cout << "secret number is smaller\n";
            }
            else
            {
                cout << "you win\n";
                cout << "tries: " << tries;
            }
        }
    } while (userNumber != secret && userNumber != 0);*/

    //task6 //Завдання 6 Написати програму-конвертер валют. Реалізувати спілкування з користувачем через меню.
    int choice;
    double money;

    cout << "currency converter\n";
    cout << "1 - dollars to grivna\n";
    cout << "2 - grivna to dollars\n";
    cout << "3 - euro to grivna\n";
    cout << "4 - grivna to euro\n";
    cout << "enter choice: ";
    cin >> choice;

    cout << "enter money: ";
    cin >> money;

    if (choice == 1)
    {
        cout << "result: " << money * 41.5 << " grn";
    }
    else if (choice == 2)
    {
        cout << "result: " << money / 41.5 << " dollars";
    }
    else if (choice == 3)
    {
        cout << "result: " << money * 44.5 << " grn";
    }
    else if (choice == 4)
    {
        cout << "result: " << money / 44.5 << " euro";
    }
    else
    {
        cout << "wrong choice";
    }

}
