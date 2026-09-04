#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

//task1 //Завдання 1 Функція додає рядок двовимірному масиву в кінець.
/*int** addRowEnd(int** arr, int& rows, int cols)
{
    int** temp = new int* [rows + 1];

    for (int i = 0; i < rows; i++)
    {
        temp[i] = arr[i];
    }

    temp[rows] = new int[cols];

    for (int j = 0; j < cols; j++)
    {
        cout << "new: ";
        cin >> temp[rows][j];
    }

    delete[] arr;
    rows++;

    return temp;
}*/

//task2 //Завдання 2 Функція додає рядок двовимірному масиву на початок.
/*int** addRowStart(int** arr, int& rows, int cols)
{
    int** temp = new int* [rows + 1];

    temp[0] = new int[cols];

    for (int j = 0; j < cols; j++)
    {
        cout << "new: ";
        cin >> temp[0][j];
    }

    for (int i = 0; i < rows; i++)
    {
        temp[i + 1] = arr[i];
    }

    delete[] arr;
    rows++;

    return temp;
}*/

//task3 //Завдання 3 Функція додає рядок двовимірному масиву в зазначену позицію.
/*int** addRowPos(int** arr, int& rows, int cols, int pos)
{
    int** temp = new int* [rows + 1];

    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[i];
    }

    temp[pos] = new int[cols];

    for (int j = 0; j < cols; j++)
    {
        cout << "new: ";
        cin >> temp[pos][j];
    }

    for (int i = pos; i < rows; i++)
    {
        temp[i + 1] = arr[i];
    }

    delete[] arr;
    rows++;

    return temp;
}*/

//task4 //Завдання 4 Видалити з двовимірного масиву рядки, що містять нульові елементи.
/*bool hasZero(int* row, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        if (row[j] == 0)
        {
            return true;
        }
    }

    return false;
}

int** deleteZeroRows(int** arr, int& rows, int cols)
{
    int newRows = 0;

    for (int i = 0; i < rows; i++)
    {
        if (hasZero(arr[i], cols) == false)
        {
            newRows++;
        }
    }

    int** temp = new int* [newRows];
    int pos = 0;

    for (int i = 0; i < rows; i++)
    {
        if (hasZero(arr[i], cols) == false)
        {
            temp[pos] = arr[i];
            pos++;
        }
        else
        {
            delete[] arr[i];
        }
    }

    delete[] arr;
    rows = newRows;

    return temp;
}*/

//task5 //Завдання 5 Поелементно підсумувати два динамічні двовимірні масиви.
/*int** sumArrays(int** a, int** b, int rows, int cols)
{
    int** c = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        c[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    return c;
}*/

//task6 //Завдання 6 Функція множення матриць.
/*int** multMatrix(int** a, int** b, int m, int n, int k)
{
    int** c = new int* [m];

    for (int i = 0; i < m; i++)
    {
        c[i] = new int[k];

        for (int j = 0; j < k; j++)
        {
            c[i][j] = 0;

            for (int x = 0; x < n; x++)
            {
                c[i][j] = c[i][j] + a[i][x] * b[x][j];
            }
        }
    }

    return c;
}*/

//task7 //Завдання 7 Функція перетворення одновимірного масиву в двовимірний.
/*int** toMatrix(int arr[], int size, int rows, int cols)
{
    if (rows <= 0 || cols <= 0 || rows * cols != size)
    {
        return 0;
    }

    int** matrix = new int* [rows];
    int pos = 0;

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];

        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = arr[pos];
            pos++;
        }
    }

    return matrix;
}*/

int main()
{
    //task8 //Завдання 8 Ввести 5 прізвищ студентів і знайти найдовше прізвище.
    char names[5][50];
    int maxIndex = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "name: ";
        cin >> names[i];

        if (strlen(names[i]) > strlen(names[maxIndex]))
        {
            maxIndex = i;
        }
    }

    cout << "longest: " << names[maxIndex];

}
