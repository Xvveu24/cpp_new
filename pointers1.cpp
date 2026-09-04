#include <iostream>
using namespace std;

//task1 //Завдання 1 Калькулятор +, -, *, / через масив покажчиків на функції, без if і switch.
/*double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mult(double a, double b)
{
    return a * b;
}

double divi(double a, double b)
{
    return a / b;
}*/

void sumArrays(int* a, int* b, int* c, int size)
{
    for (int i = 0; i < size; i++)
    {
        c[i] = a[i] + b[i];
    }
}

int main()
{
    //task1
    /*double (*actions[4])(double, double) = { add, sub, mult, divi };
    double a, b;
    int choice;

    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    cout << "0 +\n";
    cout << "1 -\n";
    cout << "2 *\n";
    cout << "3 /\n";
    cout << "choice: ";
    cin >> choice;

    cout << "result: " << actions[choice](a, b);*/

    //task2 //Завдання 2 Функція приймає покажчики на три масиви і заносить у C суми A і B.
    const int size = 5;
    int a[size] = { 2, 5, 7, 1, 9 };
    int b[size] = { 3, 4, 8, 6, 0 };
    int c[size];

    sumArrays(a, b, c, size);

    cout << "c: ";
    for (int i = 0; i < size; i++)
    {
        cout << c[i] << " ";
    }

}
