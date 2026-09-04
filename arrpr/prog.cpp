#include <iostream>
#include <ctime>
#define INTEGER
#include "function.h"
using namespace std;

int main()
{
    srand(time(0));

    const int size = 10;

#ifdef INTEGER
    int arr[size];
#endif

#ifdef DOUBLE
    double arr[size];
#endif

#ifdef CHAR
    char arr[size];
#endif

    FillArray(arr, size);

    cout << "array: ";
    ShowArray(arr, size);

    cout << "min: " << FindMin(arr, size) << '\n';
    cout << "max: " << FindMax(arr, size) << '\n';

    SortArray(arr, size);
    cout << "sort: ";
    ShowArray(arr, size);

    EditArray(arr, size);
    cout << "edit: ";
    ShowArray(arr, size);

}
