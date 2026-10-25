#include <iostream>
#include <iomanip>
#include <compare>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

    void normalize()
    {
        long long total = (long long)hours * 3600 + minutes * 60 + seconds;

        if (total < 0)
        {
            total = 0;
        }

        hours = total / 3600;
        minutes = (total % 3600) / 60;
        seconds = total % 60;
    }

    long long toSeconds() const
    {
        return (long long)hours * 3600 + minutes * 60 + seconds;
    }

public:
    Time(int hours = 0, int minutes = 0, int seconds = 0)
        : hours(hours), minutes(minutes), seconds(seconds)
    {
        normalize();
    }

    Time operator+(const Time& other) const
    {
        return Time(hours + other.hours,
            minutes + other.minutes,
            seconds + other.seconds);
    }

    Time operator-(const Time& other) const
    {
        if (toSeconds() < other.toSeconds())
        {
            return Time();
        }

        return Time(hours - other.hours,
            minutes - other.minutes,
            seconds - other.seconds);
    }

    strong_ordering operator<=>(const Time& other) const
    {
        return toSeconds() <=> other.toSeconds();
    }

    bool operator==(const Time& other) const
    {
        return toSeconds() == other.toSeconds();
    }

    Time& operator++()
    {
        seconds++;
        normalize();
        return *this;
    }

    Time operator++(int)
    {
        Time old = *this;
        ++(*this);
        return old;
    }

    Time& operator--()
    {
        if (toSeconds() > 0)
        {
            seconds--;
            normalize();
        }

        return *this;
    }

    Time operator--(int)
    {
        Time old = *this;
        --(*this);
        return old;
    }

    friend ostream& operator<<(ostream& out, const Time& time)
    {
        char oldFill = out.fill('0');
        out << setw(2) << time.hours << ':'
            << setw(2) << time.minutes << ':'
            << setw(2) << time.seconds;
        out.fill(oldFill);
        return out;
    }

    friend istream& operator>>(istream& in, Time& time)
    {
        int hours, minutes, seconds;

        if (!(in >> hours))
        {
            return in;
        }

        in >> ws;
        if (in.peek() == ':')
        {
            in.get();
        }

        if (!(in >> minutes))
        {
            return in;
        }

        in >> ws;
        if (in.peek() == ':')
        {
            in.get();
        }

        if (in >> seconds)
        {
            time = Time(hours, minutes, seconds);
        }

        return in;
    }
};

int main()
{
    Time first, second;

    cout << "first time (HH:MM:SS or H M S): ";
    cin >> first;
    cout << "second time (HH:MM:SS or H M S): ";
    cin >> second;

    cout << "sum: " << first + second << '\n';
    cout << "difference: " << first - second << '\n';

    if (first > second)
    {
        cout << "first is greater\n";
    }
    else if (first < second)
    {
        cout << "second is greater\n";
    }
    else
    {
        cout << "times are equal\n";
    }

    cout << "prefix ++ first: " << ++first << '\n';
    cout << "postfix ++ second old value: " << second++ << '\n';
    cout << "second now: " << second << '\n';
    cout << "prefix -- first: " << --first << '\n';
    cout << "postfix -- second old value: " << second-- << '\n';
    cout << "second now: " << second << '\n';
}
