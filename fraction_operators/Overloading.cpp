#include <iostream>
#include "Fraction.h"
using namespace std;

class Box
{
private:
    int width;

public:
    explicit Box(int w) : width(w) {}

    friend void PrintBoxWidth(const Box& box);
};

void PrintBoxWidth(const Box& box)
{
    cout << "Box width: " << box.width << '\n';
}

int main()
{
    Fraction first(1, 7);
    Fraction second(3, 7);

    cout << "Fraction * Fraction: " << first * second << '\n';
    cout << "int * Fraction: " << 3 * first << '\n';
    cout << "Fraction * int: " << first * 3 << '\n';

    cout << "Fraction / Fraction: " << first / second << '\n';
    cout << "int / Fraction: " << 2 / first << '\n';
    cout << "Fraction / int: " << first / 2 << '\n';

    cout << "Fraction - Fraction: " << second - first << '\n';
    cout << "int - Fraction: " << 1 - first << '\n';
    cout << "Fraction - int: " << second - 1 << '\n';

    cout << "prefix --: " << --second << '\n';
    cout << "postfix --: " << second-- << '\n';
    cout << "after postfix: " << second << '\n';

    Fraction entered;
    cout << "Enter fraction (example 4/9): ";
    if (cin >> entered)
    {
        cout << "You entered: " << entered << '\n';
    }
    else
    {
        cout << "Invalid fraction\n";
    }

    Box box(10);
    PrintBoxWidth(box);
}
