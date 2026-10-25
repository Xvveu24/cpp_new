#include <iostream>
using namespace std;

typedef double (*FindFunc)(int*, int, int*, int);

double findMax(int* a, int sizeA, int* b, int sizeB)
{
    int result = a[0];

    for (int i = 0; i < sizeA; i++)
    {
        if (a[i] > result)
        {
            result = a[i];
        }
    }

    for (int i = 0; i < sizeB; i++)
    {
        if (b[i] > result)
        {
            result = b[i];
        }
    }

    return result;
}

double findMin(int* a, int sizeA, int* b, int sizeB)
{
    int result = a[0];

    for (int i = 0; i < sizeA; i++)
    {
        if (a[i] < result)
        {
            result = a[i];
        }
    }

    for (int i = 0; i < sizeB; i++)
    {
        if (b[i] < result)
        {
            result = b[i];
        }
    }

    return result;
}

double findAverage(int* a, int sizeA, int* b, int sizeB)
{
    int sum = 0;

    for (int i = 0; i < sizeA; i++)
    {
        sum = sum + a[i];
    }

    for (int i = 0; i < sizeB; i++)
    {
        sum = sum + b[i];
    }

    return (double)sum / (sizeA + sizeB);
}

double Action(int* a, int sizeA, int* b, int sizeB, FindFunc find)
{
    return find(a, sizeA, b, sizeB);
}

int main()
{
    int sizeA, sizeB;

    cout << "size A: ";
    cin >> sizeA;
    cout << "size B: ";
    cin >> sizeB;

    if (sizeA <= 0 || sizeB <= 0 || sizeA > 100 || sizeB > 100)
    {
        cout << "wrong size";
        return 0;
    }

    int a[100], b[100];

    cout << "A: ";
    for (int i = 0; i < sizeA; i++)
    {
        cin >> a[i];
    }

    cout << "B: ";
    for (int i = 0; i < sizeB; i++)
    {
        cin >> b[i];
    }

    int choice;
    FindFunc find;

    cout << "1-max\n";
    cout << "2-min\n";
    cout << "3-avg\n";
    cout << "choice: ";
    cin >> choice;

    if (choice == 1)
    {
        find = findMax;
    }
    else if (choice == 2)
    {
        find = findMin;
    }
    else if (choice == 3)
    {
        find = findAverage;
    }
    else
    {
        cout << "wrong choice";
        return 0;
    }

    cout << "result: " << Action(a, sizeA, b, sizeB, find);
}
