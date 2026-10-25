#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array<int> arr;

    arr.insertAt(0, 1);
    arr.insertAt(1, 2);
    arr.insertAt(2, 3);
    cout << arr << '\n';

    arr.insertAt(1, 10);
    cout << arr << '\n';

    arr.removeAt(2);
    cout << arr << '\n';

    arr.pushFront(0);
    cout << arr << '\n';

    arr.popFront();
    cout << arr << '\n';

    arr.clear();
    cout << arr << '\n';
    cout << "empty: " << arr.empty() << '\n';

    arr.popFront();
    cout << arr << '\n';
}
