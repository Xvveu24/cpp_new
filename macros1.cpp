#include <iostream>
#include <cmath>
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SQUARE(a) ((a) * (a))
#define POWER(a, p) (pow((a), (p)))
#define EVEN(a) ((a) % 2 == 0)
#define ODD(a) ((a) % 2 != 0)

int main()
{
    int a, b, p;

    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "power: ";
    cin >> p;

    cout << "min: " << MIN(a, b) << '\n';
    cout << "max: " << MAX(a, b) << '\n';
    cout << "square a: " << SQUARE(a) << '\n';
    cout << "a power p: " << POWER(a, p) << '\n';

    if (EVEN(a))
    {
        cout << "a even\n";
    }
    else
    {
        cout << "a not even\n";
    }

    if (ODD(a))
    {
        cout << "a odd";
    }
    else
    {
        cout << "a not odd";
    }

}
