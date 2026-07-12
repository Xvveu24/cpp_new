#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//task1 //Завдання 1 Рекурсивна функція знаходження степеня числа.
double power(double number, int degree)
{
    if (degree == 0)
    {
        return 1;
    }

    return number * power(number, degree - 1);
}

//task2 //Завдання 2 Рекурсивна функція, яка виводить N зірок у ряд.
void stars(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << "*";
    stars(n - 1);
}

//task3 //Завдання 3 Рекурсивна функція, яка обчислює суму всіх чисел у діапазоні від a до b.
int sumRange(int a, int b)
{
    if (a > b)
    {
        return 0;
    }

    return a + sumRange(a + 1, b);
}

int sumTen(int arr[100], int pos, int count)
{
    if (count == 0)
    {
        return 0;
    }

    return arr[pos] + sumTen(arr, pos + 1, count - 1);
}

int findMinPos(int arr[100], int pos, int minPos, int minSum)
{
    if (pos > 90)
    {
        return minPos;
    }

    int sum = sumTen(arr, pos, 10);

    if (sum < minSum)
    {
        minSum = sum;
        minPos = pos;
    }

    return findMinPos(arr, pos + 1, minPos, minSum);
}

int main()
{
    //task4 //Завдання 4 Рекурсивна функція знаходить позицію, з якої починається послідовність з 10 чисел з мінімальною сумою.
    srand(time(0));

    int arr[100];

    for (int i = 0; i < 100; i++)
    {
        arr[i] = rand() % 41 - 20;
        cout << arr[i] << " ";
    }

    int minSum = sumTen(arr, 0, 10);
    int pos = findMinPos(arr, 1, 0, minSum);

    cout << "\npos: " << pos;
    cout << "\nsum: " << sumTen(arr, pos, 10);

}
