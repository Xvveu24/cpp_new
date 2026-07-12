#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //task1 //Завдання 1 Створити двовимірний масив. Перше число вводить користувач, кожне наступне множиться на 2.
    /*int arr[3][4];
    int number;

    cout << "number: ";
    cin >> number;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = number;
            number = number * 2;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }*/

    //task2 //Завдання 2 Створити двовимірний масив. Перше число вводить користувач, кожне наступне збільшується на 1.
    /*int arr[3][4];
    int number;

    cout << "number: ";
    cin >> number;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = number;
            number++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }*/

    //task3 //Завдання 3 Заповнити двовимірний масив випадковими числами. Виконати циклічний зсув.
    srand(time(0));

    int arr[3][4];
    int shift, side;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    cout << "array:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    cout << "shift: ";
    cin >> shift;

    cout << "1-left 2-right 3-up 4-down: ";
    cin >> side;

    shift = shift % 4;

    if (side == 1)
    {
        for (int s = 0; s < shift; s++)
        {
            for (int i = 0; i < 3; i++)
            {
                int temp = arr[i][0];

                for (int j = 0; j < 3; j++)
                {
                    arr[i][j] = arr[i][j + 1];
                }

                arr[i][3] = temp;
            }
        }
    }
    else if (side == 2)
    {
        for (int s = 0; s < shift; s++)
        {
            for (int i = 0; i < 3; i++)
            {
                int temp = arr[i][3];

                for (int j = 3; j > 0; j--)
                {
                    arr[i][j] = arr[i][j - 1];
                }

                arr[i][0] = temp;
            }
        }
    }
    else if (side == 3)
    {
        shift = shift % 3;

        for (int s = 0; s < shift; s++)
        {
            for (int j = 0; j < 4; j++)
            {
                int temp = arr[0][j];

                for (int i = 0; i < 2; i++)
                {
                    arr[i][j] = arr[i + 1][j];
                }

                arr[2][j] = temp;
            }
        }
    }
    else if (side == 4)
    {
        shift = shift % 3;

        for (int s = 0; s < shift; s++)
        {
            for (int j = 0; j < 4; j++)
            {
                int temp = arr[2][j];

                for (int i = 2; i > 0; i--)
                {
                    arr[i][j] = arr[i - 1][j];
                }

                arr[0][j] = temp;
            }
        }
    }
    else
    {
        cout << "wrong side\n";
    }

    cout << "result:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

}
