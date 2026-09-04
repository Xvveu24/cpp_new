#include <iostream>
#include <cstdlib>
#include "function.h"
using namespace std;

void FillArrayInt(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

void ShowArrayInt(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int FindMinInt(int arr[], int size)
{
    int minNumber = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minNumber)
        {
            minNumber = arr[i];
        }
    }

    return minNumber;
}

int FindMaxInt(int arr[], int size)
{
    int maxNumber = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxNumber)
        {
            maxNumber = arr[i];
        }
    }

    return maxNumber;
}

void SortArrayInt(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void EditArrayInt(int arr[], int size)
{
    int index;
    int value;

    cout << "index: ";
    cin >> index;
    cout << "value: ";
    cin >> value;

    if (index >= 0 && index < size)
    {
        arr[index] = value;
    }
}

void FillArrayDouble(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 1000) / 10.0;
    }
}

void ShowArrayDouble(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

double FindMinDouble(double arr[], int size)
{
    double minNumber = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minNumber)
        {
            minNumber = arr[i];
        }
    }

    return minNumber;
}

double FindMaxDouble(double arr[], int size)
{
    double maxNumber = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxNumber)
        {
            maxNumber = arr[i];
        }
    }

    return maxNumber;
}

void SortArrayDouble(double arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void EditArrayDouble(double arr[], int size)
{
    int index;
    double value;

    cout << "index: ";
    cin >> index;
    cout << "value: ";
    cin >> value;

    if (index >= 0 && index < size)
    {
        arr[index] = value;
    }
}

void FillArrayChar(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 'A' + rand() % 26;
    }
}

void ShowArrayChar(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

char FindMinChar(char arr[], int size)
{
    char minSymbol = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < minSymbol)
        {
            minSymbol = arr[i];
        }
    }

    return minSymbol;
}

char FindMaxChar(char arr[], int size)
{
    char maxSymbol = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxSymbol)
        {
            maxSymbol = arr[i];
        }
    }

    return maxSymbol;
}

void SortArrayChar(char arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void EditArrayChar(char arr[], int size)
{
    int index;
    char value;

    cout << "index: ";
    cin >> index;
    cout << "value: ";
    cin >> value;

    if (index >= 0 && index < size)
    {
        arr[index] = value;
    }
}
