#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //task1 //Завдання 1 В одновимірному масиві, заповненому випадковими числами, визначити мінімальний і максимальний елементи.
    /*srand(time(0));

    int arr[10];
    int minNumber, maxNumber;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    minNumber = arr[0];
    maxNumber = arr[0];

    for (int i = 1; i < 10; i++)
    {
        if (arr[i] < minNumber)
        {
            minNumber = arr[i];
        }
        if (arr[i] > maxNumber)
        {
            maxNumber = arr[i];
        }
    }

    cout << "\nmin: " << minNumber;
    cout << "\nmax: " << maxNumber;*/

    //task2 //Завдання 2 Користувач вводить прибуток за 12 місяців і діапазон. Знайти місяць з min і max прибутком у цьому діапазоні.
    /*double profit[12];
    int startMonth, endMonth;

    for (int i = 0; i < 12; i++)
    {
        cout << "month " << i + 1 << ": ";
        cin >> profit[i];
    }

    cout << "start: ";
    cin >> startMonth;
    cout << "end: ";
    cin >> endMonth;

    if (startMonth > endMonth)
    {
        int temp = startMonth;
        startMonth = endMonth;
        endMonth = temp;
    }

    int minMonth = startMonth - 1;
    int maxMonth = startMonth - 1;

    for (int i = startMonth - 1; i <= endMonth - 1; i++)
    {
        if (profit[i] < profit[minMonth])
        {
            minMonth = i;
        }
        if (profit[i] > profit[maxMonth])
        {
            maxMonth = i;
        }
    }

    cout << "min month: " << minMonth + 1;
    cout << "\nmax month: " << maxMonth + 1;*/

    //task3 //Завдання 3 В масиві з N дійсних чисел обчислити суму від'ємних, добутки і суму між першим та останнім від'ємними.
    /*int n;

    cout << "n: ";
    cin >> n;

    double arr[100];
    double sumNegative = 0;
    double multMinMax = 1;
    double multEven = 1;
    double sumBetweenNeg = 0;
    int minIndex = 0, maxIndex = 0;
    int firstNeg = -1, lastNeg = -1;

    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];

        if (arr[i] < 0)
        {
            sumNegative = sumNegative + arr[i];

            if (firstNeg == -1)
            {
                firstNeg = i;
            }

            lastNeg = i;
        }

        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }

        if (i % 2 == 0)
        {
            multEven = multEven * arr[i];
        }
    }

    int start, end;

    if (minIndex < maxIndex)
    {
        start = minIndex + 1;
        end = maxIndex;
    }
    else
    {
        start = maxIndex + 1;
        end = minIndex;
    }

    for (int i = start; i < end; i++)
    {
        multMinMax = multMinMax * arr[i];
    }

    if (firstNeg != -1 && firstNeg != lastNeg)
    {
        for (int i = firstNeg + 1; i < lastNeg; i++)
        {
            sumBetweenNeg = sumBetweenNeg + arr[i];
        }
    }

    cout << "sum negative: " << sumNegative;
    cout << "\nmult min max: " << multMinMax;
    cout << "\nmult even: " << multEven;
    cout << "\nsum between neg: " << sumBetweenNeg;*/

    //task4 //Завдання 4 Скопіювати послідовно елементи одного масиву розміром 10 у 2 масиви розміром 5.
    /*int arr[10];
    int first[5], second[5];

    for (int i = 0; i < 10; i++)
    {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        first[i] = arr[i];
        second[i] = arr[i + 5];
    }

    cout << "first: ";
    for (int i = 0; i < 5; i++)
    {
        cout << first[i] << " ";
    }

    cout << "\nsecond: ";
    for (int i = 0; i < 5; i++)
    {
        cout << second[i] << " ";
    }*/

    //task5 //Завдання 5 Виконати поелементну суму двох масивів і результат занести у третій масив.
    int arr1[5] = { 10, 15, 0, -23, 40 };
    int arr2[5] = { 6, 0, -100, 25, -4 };
    int result[5];

    for (int i = 0; i < 5; i++)
    {
        result[i] = arr1[i] + arr2[i];
    }

    cout << "result: ";
    for (int i = 0; i < 5; i++)
    {
        cout << result[i] << " ";
    }

}
