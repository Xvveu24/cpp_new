#include <iostream>
#include <string>
using namespace std;

/*task1
class Book
{
private:
    string author;
    string title;
    string publisher;
    int year;
    int count;
    int pages;

public:
    explicit Book(string author, string title, string publisher,
        int year, int count, int pages)
        : author(author), title(title), publisher(publisher),
          year(year), count(count), pages(pages) {}

    string getAuthor() const { return author; }
    string getPublisher() const { return publisher; }
    int getYear() const { return year; }

    void show() const
    {
        cout << title << ", " << author << ", " << publisher << ", ";
        cout << year << ", " << count << " copies, " << pages << " pages\n";
    }
};
*/

class Worker
{
private:
    string fullName;
    string position;
    int startYear;
    double salary;

public:
    explicit Worker(string fullName, string position, int startYear, double salary)
        : fullName(fullName), position(position), startYear(startYear), salary(salary) {}

    int getStartYear() const { return startYear; }
    double getSalary() const { return salary; }
    string getPosition() const { return position; }

    void show() const
    {
        cout << fullName << " | " << position << " | ";
        cout << startYear << " | " << salary << '\n';
    }
};

int main()
{
    //task1 //Для Book вивести книги автора, видавництва та після заданого року.
    /*Book books[4] = {
        Book("Ivan Franko", "Zakhar Berkut", "A-BA-BA-HA-LA-MA-HA", 1883, 1000, 240),
        Book("Lesya Ukrainka", "Forest Song", "Vydavnytstvo Staroho Leva", 1911, 800, 160),
        Book("Ivan Franko", "Moses", "A-BA-BA-HA-LA-MA-HA", 1905, 500, 120),
        Book("Taras Shevchenko", "Kobzar", "Rannia", 1840, 1200, 300)
    };

    string author, publisher;
    int year;

    cout << "author: ";
    getline(cin, author);
    cout << "publisher: ";
    getline(cin, publisher);
    cout << "year: ";
    cin >> year;

    cout << "\nby author:\n";
    for (int i = 0; i < 4; i++)
    {
        if (books[i].getAuthor() == author)
        {
            books[i].show();
        }
    }

    cout << "\nby publisher:\n";
    for (int i = 0; i < 4; i++)
    {
        if (books[i].getPublisher() == publisher)
        {
            books[i].show();
        }
    }

    cout << "\nafter year:\n";
    for (int i = 0; i < 4; i++)
    {
        if (books[i].getYear() > year)
        {
            books[i].show();
        }
    }*/

    //task2 //Для Worker вивести працівників за стажем, зарплатою та посадою.
    Worker workers[5] = {
        Worker("Ivan Petrenko", "Manager", 2018, 25000),
        Worker("Olena Shevchenko", "Accountant", 2020, 22000),
        Worker("Maksym Kovalenko", "Manager", 2015, 32000),
        Worker("Anna Bondar", "Designer", 2022, 18000),
        Worker("Dmytro Melnyk", "Developer", 2019, 40000)
    };

    int currentYear;
    int years;
    double salary;
    string position;

    cout << "current year: ";
    cin >> currentYear;
    cout << "years of work: ";
    cin >> years;
    cout << "salary: ";
    cin >> salary;
    cin.ignore();
    cout << "position: ";
    getline(cin, position);

    cout << "\nby experience:\n";
    for (int i = 0; i < 5; i++)
    {
        if (currentYear - workers[i].getStartYear() > years)
        {
            workers[i].show();
        }
    }

    cout << "\nby salary:\n";
    for (int i = 0; i < 5; i++)
    {
        if (workers[i].getSalary() > salary)
        {
            workers[i].show();
        }
    }

    cout << "\nby position:\n";
    for (int i = 0; i < 5; i++)
    {
        if (workers[i].getPosition() == position)
        {
            workers[i].show();
        }
    }
}
