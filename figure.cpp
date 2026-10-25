#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

class Figure
{
public:
    virtual double GetArea() const = 0;
    virtual ~Figure() = default;
};

class Rectangle : public Figure
{
private:
    double width;
    double height;

public:
    Rectangle(double figureWidth, double figureHeight)
        : width(figureWidth), height(figureHeight)
    {
    }

    double GetArea() const override
    {
        return width * height;
    }
};

class Circle : public Figure
{
private:
    double radius;

public:
    explicit Circle(double figureRadius) : radius(figureRadius)
    {
    }

    double GetArea() const override
    {
        return 3.141592653589793 * radius * radius;
    }
};

class Triangle : public Figure
{
private:
    double base;
    double height;

public:
    Triangle(double triangleBase, double triangleHeight)
        : base(triangleBase), height(triangleHeight)
    {
    }

    double GetArea() const override
    {
        return base * height / 2.0;
    }
};

int main()
{
    cout << "Choose figure:\n";
    cout << "1. Rectangle\n2. Circle\n3. Triangle\n";

    int choice;
    cin >> choice;

    Figure* figure = nullptr;
    double width;
    double height;
    double radius;

    if (choice == 1)
    {
        cout << "Enter width and height: ";
        cin >> width >> height;
        figure = new Rectangle(width, height);
    }
    else if (choice == 2)
    {
        cout << "Enter radius: ";
        cin >> radius;
        figure = new Circle(radius);
    }
    else if (choice == 3)
    {
        cout << "Enter base and height: ";
        cin >> width >> height;
        figure = new Triangle(width, height);
    }
    else
    {
        cout << "Wrong choice.\n";
        return 0;
    }

    cout << fixed << setprecision(2);
    cout << "Area: " << figure->GetArea() << '\n';

    delete figure;
}
