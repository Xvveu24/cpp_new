#include <iostream>
using namespace std;

int main()
{
    //task1 //Завдання 1 Користувач вводить прибуток за кожен місяць. Знайти суму, min, max і середній прибуток.
    /*double profit[12];
    double sum = 0;
    int minMonth = 0;
    int maxMonth = 0;

    for (int i = 0; i < 12; i++)
    {
        cout << "month " << i + 1 << ": ";
        cin >> profit[i];

        sum = sum + profit[i];

        if (profit[i] < profit[minMonth])
        {
            minMonth = i;
        }
        if (profit[i] > profit[maxMonth])
        {
            maxMonth = i;
        }
    }

    double average = sum / 12;

    cout << "sum: " << sum;
    cout << "\nmax month: " << maxMonth + 1;
    cout << "\nmin month: " << minMonth + 1;
    cout << "\naverage: " << average;*/

    //task2 //Завдання 2 Створити масив на 10 елементів і вивести його в зворотному порядку.
    /*int arr[10] = { 4, 7, -2, 0, 15, 8, -9, 3, 11, 6 };

    for (int i = 9; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }*/

    //task3 //Завдання 3 Користувач вводить довжину сторін п'ятикутника. Обчислити периметр.
    /*double sides[5];
    double perimeter = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "side " << i + 1 << ": ";
        cin >> sides[i];
        perimeter = perimeter + sides[i];
    }

    cout << "p: " << perimeter;*/

    //task4 //Завдання 4 Стиснути масив, видаливши всі 0, а вільні елементи справа заповнити -1.
    /*int arr[9] = { 0, -11, 0, 12, 54, 0, 0, -40, 11 };
    int pos = 0;

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] != 0)
        {
            arr[pos] = arr[i];
            pos++;
        }
    }

    for (int i = pos; i < 9; i++)
    {
        arr[i] = -1;
    }

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }*/

    //task5 //Завдання 5 Скопіювати 2 масиви в один: спочатку >0, потім 0, потім <0.
    int arr1[5] = { 10, 0, 52, -10, -44 };
    int arr2[5] = { 54, 0, -100, 12, 4 };
    int result[10];
    int pos = 0;

    for (int i = 0; i < 5; i++)
    {
        if (arr1[i] > 0)
        {
            result[pos] = arr1[i];
            pos++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr2[i] > 0)
        {
            result[pos] = arr2[i];
            pos++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr1[i] == 0)
        {
            result[pos] = arr1[i];
            pos++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr2[i] == 0)
        {
            result[pos] = arr2[i];
            pos++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr1[i] < 0)
        {
            result[pos] = arr1[i];
            pos++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (arr2[i] < 0)
        {
            result[pos] = arr2[i];
            pos++;
        }
    }

    cout << "result: ";
    for (int i = 0; i < 10; i++)
    {
        cout << result[i] << " ";
    }

}
