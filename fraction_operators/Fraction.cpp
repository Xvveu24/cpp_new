#include "Fraction.h"
#include <cmath>
#include <stdexcept>

namespace
{
    int getGCD(int a, int b)
    {
        a = std::abs(a);
        b = std::abs(b);

        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a == 0 ? 1 : a;
    }
}

Fraction::Fraction(int num, int denom)
    : numerator(num), denominator(denom)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }

    simplify();
}

void Fraction::simplify()
{
    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction Fraction::add(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator);
}

Fraction Fraction::operator+(const Fraction& right) const
{
    return Fraction(numerator * right.denominator + right.numerator * denominator,
        denominator * right.denominator);
}

Fraction Fraction::operator+(int right) const
{
    return Fraction(numerator + right * denominator, denominator);
}

Fraction operator+(int left, const Fraction& right)
{
    return right + left;
}

Fraction Fraction::operator-(const Fraction& right) const
{
    return Fraction(numerator * right.denominator - right.numerator * denominator,
        denominator * right.denominator);
}

Fraction Fraction::operator-(int right) const
{
    return Fraction(numerator - right * denominator, denominator);
}

Fraction operator-(int left, const Fraction& right)
{
    return Fraction(left * right.denominator - right.numerator, right.denominator);
}

Fraction Fraction::operator*(const Fraction& right) const
{
    return Fraction(numerator * right.numerator, denominator * right.denominator);
}

Fraction Fraction::operator*(int right) const
{
    return Fraction(numerator * right, denominator);
}

Fraction operator*(int left, const Fraction& right)
{
    return right * left;
}

Fraction Fraction::operator/(const Fraction& right) const
{
    if (right.numerator == 0)
    {
        throw std::domain_error("Division by zero");
    }

    return Fraction(numerator * right.denominator, denominator * right.numerator);
}

Fraction Fraction::operator/(int right) const
{
    if (right == 0)
    {
        throw std::domain_error("Division by zero");
    }

    return Fraction(numerator, denominator * right);
}

Fraction operator/(int left, const Fraction& right)
{
    if (right.numerator == 0)
    {
        throw std::domain_error("Division by zero");
    }

    return Fraction(left * right.denominator, right.numerator);
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.numerator << '/' << fraction.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
    int num, denom;
    char slash;

    if (in >> num >> slash >> denom)
    {
        if (slash != '/' || denom == 0)
        {
            in.setstate(std::ios::failbit);
        }
        else
        {
            fraction.numerator = num;
            fraction.denominator = denom;
            fraction.simplify();
        }
    }

    return in;
}

Fraction& Fraction::operator++()
{
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction old = *this;
    ++(*this);
    return old;
}

Fraction& Fraction::operator--()
{
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction old = *this;
    --(*this);
    return old;
}
