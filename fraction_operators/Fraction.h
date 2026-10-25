#pragma once
#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;

    void simplify();

public:
    Fraction(int num = 0, int denom = 1);

    static Fraction add(const Fraction& f1, const Fraction& f2);

    Fraction operator+(const Fraction& right) const;
    Fraction operator+(int right) const;
    friend Fraction operator+(int left, const Fraction& right);

    Fraction operator-(const Fraction& right) const;
    Fraction operator-(int right) const;
    friend Fraction operator-(int left, const Fraction& right);

    Fraction operator*(const Fraction& right) const;
    Fraction operator*(int right) const;
    friend Fraction operator*(int left, const Fraction& right);

    Fraction operator/(const Fraction& right) const;
    Fraction operator/(int right) const;
    friend Fraction operator/(int left, const Fraction& right);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);

    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
};
