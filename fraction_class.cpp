#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        if (a < 0)
        {
            a = -a;
        }
        if (b < 0)
        {
            b = -b;
        }

        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    void reduce()
    {
        int divisor = gcd(numerator, denominator);

        if (divisor != 0)
        {
            numerator = numerator / divisor;
            denominator = denominator / divisor;
        }

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }

    void input()
    {
        cout << "numerator: ";
        cin >> numerator;

        do
        {
            cout << "denominator: ";
            cin >> denominator;
        } while (denominator == 0);

        reduce();
    }

    void show()
    {
        cout << numerator << "/" << denominator;
    }

    Fraction add(Fraction other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.reduce();
        return result;
    }

    Fraction subtract(Fraction other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.reduce();
        return result;
    }

    Fraction multiply(Fraction other)
    {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        result.reduce();
        return result;
    }

    Fraction divide(Fraction other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        result.reduce();
        return result;
    }

    bool canDivide(Fraction other)
    {
        return other.numerator != 0;
    }
};

int main()
{
    Fraction first, second, result;

    cout << "first fraction\n";
    first.input();

    cout << "second fraction\n";
    second.input();

    cout << "sum: ";
    result = first.add(second);
    result.show();

    cout << "\ndifference: ";
    result = first.subtract(second);
    result.show();

    cout << "\nproduct: ";
    result = first.multiply(second);
    result.show();

    cout << '\n';
    if (first.canDivide(second))
    {
        cout << "division: ";
        result = first.divide(second);
        result.show();
    }
    else
    {
        cout << "division by zero";
    }
}
