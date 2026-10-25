#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{
    DynamicArray<int> arr;

    arr.insertAt(0, 1);
    arr.insertAt(1, 2);
    arr.insertAt(2, 3);
    cout << arr << '\n';

    arr.insertAt(1, 10);
    cout << arr << '\n';

    arr.removeAt(2);
    cout << arr << '\n';

    arr.clear();
    cout << arr << '\n';
}
