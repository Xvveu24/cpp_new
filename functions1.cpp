#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//task1 //Завдання 1 Перевантажені функції для int, double, char: матриця, виведення, min/max діагоналі, сортування рядків.
/*void initMatrix(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = rand() % 20;
        }
    }
}

void initMatrix(double arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = (rand() % 200) / 10.0;
        }
    }
}

void initMatrix(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = 'A' + rand() % 26;
        }
    }
}

void showMatrix(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

void showMatrix(double arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

void showMatrix(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

void diagMinMax(int arr[3][3])
{
    int minNumber = arr[0][0];
    int maxNumber = arr[0][0];

    for (int i = 1; i < 3; i++)
    {
        if (arr[i][i] < minNumber)
        {
            minNumber = arr[i][i];
        }
        if (arr[i][i] > maxNumber)
        {
            maxNumber = arr[i][i];
        }
    }

    cout << "min: " << minNumber << '\n';
    cout << "max: " << maxNumber << '\n';
}

void diagMinMax(double arr[3][3])
{
    double minNumber = arr[0][0];
    double maxNumber = arr[0][0];

    for (int i = 1; i < 3; i++)
    {
        if (arr[i][i] < minNumber)
        {
            minNumber = arr[i][i];
        }
        if (arr[i][i] > maxNumber)
        {
            maxNumber = arr[i][i];
        }
    }

    cout << "min: " << minNumber << '\n';
    cout << "max: " << maxNumber << '\n';
}

void diagMinMax(char arr[3][3])
{
    char minSymbol = arr[0][0];
    char maxSymbol = arr[0][0];

    for (int i = 1; i < 3; i++)
    {
        if (arr[i][i] < minSymbol)
        {
            minSymbol = arr[i][i];
        }
        if (arr[i][i] > maxSymbol)
        {
            maxSymbol = arr[i][i];
        }
    }

    cout << "min: " << minSymbol << '\n';
    cout << "max: " << maxSymbol << '\n';
}

void sortRows(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int a = 0; a < 2; a++)
        {
            for (int j = 0; j < 2 - a; j++)
            {
                if (arr[i][j] > arr[i][j + 1])
                {
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][j + 1];
                    arr[i][j + 1] = temp;
                }
            }
        }
    }
}

void sortRows(double arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int a = 0; a < 2; a++)
        {
            for (int j = 0; j < 2 - a; j++)
            {
                if (arr[i][j] > arr[i][j + 1])
                {
                    double temp = arr[i][j];
                    arr[i][j] = arr[i][j + 1];
                    arr[i][j + 1] = temp;
                }
            }
        }
    }
}

void sortRows(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int a = 0; a < 2; a++)
        {
            for (int j = 0; j < 2 - a; j++)
            {
                if (arr[i][j] > arr[i][j + 1])
                {
                    char temp = arr[i][j];
                    arr[i][j] = arr[i][j + 1];
                    arr[i][j + 1] = temp;
                }
            }
        }
    }
}*/

//task2 //Завдання 2 Рекурсивна функція знаходження найбільшого спільного дільника двох цілих чисел.
/*int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}*/

int hasDigit(int number, int digit)
{
    if (number == 0)
    {
        return 0;
    }

    if (number % 10 == digit)
    {
        return 1;
    }

    return hasDigit(number / 10, digit);
}

int playGame(int secret, int tries)
{
    int number;
    int bulls = 0;
    int cows = 0;

    cout << "number: ";
    cin >> number;

    if (number == secret)
    {
        cout << "win\n";
        return tries + 1;
    }

    int s = secret;
    int n = number;

    for (int i = 0; i < 4; i++)
    {
        int secretDigit = s % 10;
        int userDigit = n % 10;

        if (secretDigit == userDigit)
        {
            cows++;
        }

        if (hasDigit(secret, userDigit) == 1)
        {
            bulls++;
        }

        s = s / 10;
        n = n / 10;
    }

    cout << "bulls: " << bulls << '\n';
    cout << "cows: " << cows << '\n';

    return playGame(secret, tries + 1);
}

int main()
{
    //task3 //Завдання 3 Гра "Бики та корови". Програма загадує чотирицифрове число. Використати рекурсію.
    srand(time(0));

    int secret = rand() % 9000 + 1000;

    cout << "guess 4 digits\n";

    int tries = playGame(secret, 0);

    cout << "tries: " << tries;

}
