#include <iostream>
using namespace std;

//task1 //Завдання 1 Функція виводить кожен біт числа.
/*void showBits(unsigned int number)
{
    for (int i = 31; i >= 0; i--)
    {
        cout << ((number >> i) & 1);
    }
}*/

//task2 //Завдання 2 Перевірити парність числа за допомогою побітових операцій.
/*bool isEven(int number)
{
    return (number & 1) == 0;
}

bool isOdd(int number)
{
    return (number & 1) == 1;
}*/

//task3 //Завдання 3 Функція очищає біт під заданим індексом.
/*int clearBit(int number, int index)
{
    return number & ~(1 << index);
}*/

//task4 //Завдання 4 Функція встановлює біт під заданим індексом в 1.
/*int setBit(int number, int index)
{
    return number | (1 << index);
}*/

//task5 //Завдання 5 Функція інвертує біт під заданим індексом.
/*int invertBit(int number, int index)
{
    return number ^ (1 << index);
}*/

//task6 //Завдання 6 Функція підраховує кількість одиничних і нульових бітів у числі.
/*void countBits(unsigned int number)
{
    int ones = 0;
    int zeros = 0;

    for (int i = 0; i < 32; i++)
    {
        if ((number >> i) & 1)
        {
            ones++;
        }
        else
        {
            zeros++;
        }
    }

    cout << "ones: " << ones << '\n';
    cout << "zeros: " << zeros;
}*/

//task7 //Завдання 7 Перевірити, чи є число степенем двійки.
/*bool isPowerOfTwo(int number)
{
    return number > 0 && (number & (number - 1)) == 0;
}*/

//task8 //Завдання 8 Отримати індекс молодшого встановленого біта.
/*int firstOneBit(int number)
{
    if (number == 0)
    {
        return -1;
    }

    int index = 0;

    while ((number & 1) == 0)
    {
        number = number >> 1;
        index++;
    }

    return index;
}*/

int clearLowestBit(int number)
{
    return number & (number - 1);
}

int main()
{
    //task9 //Завдання 9 Функція обнулює наймолодший встановлений біт у числі.
    int number;

    cout << "number: ";
    cin >> number;

    cout << "result: " << clearLowestBit(number);

}
