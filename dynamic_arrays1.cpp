#include <iostream>
#include <cstring>
using namespace std;

//task1 //Завдання 1 Функція додає стовпчик у двовимірний масив у вказану позицію.
/*void addColumn(int arr[10][10], int rows, int& cols, int pos)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = cols; j > pos; j--)
        {
            arr[i][j] = arr[i][j - 1];
        }

        cout << "new value: ";
        cin >> arr[i][pos];
    }

    cols++;
}*/

//task2 //Завдання 2 Функція видаляє стовпчик двовимірного масиву за номером.
/*void deleteColumn(int arr[10][10], int rows, int& cols, int pos)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = pos; j < cols - 1; j++)
        {
            arr[i][j] = arr[i][j + 1];
        }
    }

    cols--;
}*/

//task3 //Завдання 3 Функція циклічного зсуву рядків або стовпчиків матриці.
/*void shiftMatrix(int arr[10][10], int rows, int cols, int count, int side)
{
    if (side == 1)
    {
        count = count % cols;
    }
    else if (side == 2)
    {
        count = count % cols;
    }
    else
    {
        count = count % rows;
    }

    for (int step = 0; step < count; step++)
    {
        if (side == 1)
        {
            for (int i = 0; i < rows; i++)
            {
                int temp = arr[i][0];

                for (int j = 0; j < cols - 1; j++)
                {
                    arr[i][j] = arr[i][j + 1];
                }

                arr[i][cols - 1] = temp;
            }
        }
        else if (side == 2)
        {
            for (int i = 0; i < rows; i++)
            {
                int temp = arr[i][cols - 1];

                for (int j = cols - 1; j > 0; j--)
                {
                    arr[i][j] = arr[i][j - 1];
                }

                arr[i][0] = temp;
            }
        }
        else if (side == 3)
        {
            for (int j = 0; j < cols; j++)
            {
                int temp = arr[0][j];

                for (int i = 0; i < rows - 1; i++)
                {
                    arr[i][j] = arr[i + 1][j];
                }

                arr[rows - 1][j] = temp;
            }
        }
        else if (side == 4)
        {
            for (int j = 0; j < cols; j++)
            {
                int temp = arr[rows - 1][j];

                for (int i = rows - 1; i > 0; i--)
                {
                    arr[i][j] = arr[i - 1][j];
                }

                arr[0][j] = temp;
            }
        }
    }
}*/

//task4 //Завдання 4 Функція транспонування матриці.
/*void transpose(int arr[10][10], int trans[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            trans[j][i] = arr[i][j];
        }
    }
}*/

//task5 //Завдання 5 Динамічний масив: ім'я і телефон. Пошук та зміна даних.
/*int main()
{
    int n;
    cout << "n: ";
    cin >> n;

    char** book = new char* [n * 2];

    for (int i = 0; i < n * 2; i++)
    {
        book[i] = new char[50];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "name: ";
        cin >> book[i * 2];
        cout << "phone: ";
        cin >> book[i * 2 + 1];
    }

    int choice;
    cout << "1-find name 2-find phone 3-change: ";
    cin >> choice;

    if (choice == 1)
    {
        char name[50];
        cout << "name: ";
        cin >> name;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(book[i * 2], name) == 0)
            {
                cout << book[i * 2] << " " << book[i * 2 + 1];
            }
        }
    }
    else if (choice == 2)
    {
        char phone[50];
        cout << "phone: ";
        cin >> phone;

        for (int i = 0; i < n; i++)
        {
            if (strcmp(book[i * 2 + 1], phone) == 0)
            {
                cout << book[i * 2] << " " << book[i * 2 + 1];
            }
        }
    }
    else if (choice == 3)
    {
        int index;
        cout << "number: ";
        cin >> index;

        cout << "name: ";
        cin >> book[(index - 1) * 2];
        cout << "phone: ";
        cin >> book[(index - 1) * 2 + 1];
    }

    for (int i = 0; i < n * 2; i++)
    {
        delete[] book[i];
    }

    delete[] book;
}*/

//task6 //Завдання 6 Ввести 5 прізвищ студентів і відсортувати їх за зростанням.
/*int main()
{
    char names[5][30];

    for (int i = 0; i < 5; i++)
    {
        cout << "name: ";
        cin >> names[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char temp[30];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << names[i] << '\n';
    }
}*/

bool exists(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return true;
        }
    }

    return false;
}

bool inMatrix(int** arr, int rows, int cols, int value)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == value)
            {
                return true;
            }
        }
    }

    return false;
}

int countInAll(int** a, int ar, int ac, int** b, int br, int bc, int** c, int cr, int cc, int value)
{
    int count = 0;

    if (inMatrix(a, ar, ac, value))
    {
        count++;
    }
    if (inMatrix(b, br, bc, value))
    {
        count++;
    }
    if (inMatrix(c, cr, cc, value))
    {
        count++;
    }

    return count;
}

int main()
{
    //task7 //Завдання 7 Для трьох матриць A, B, C створити масиви загальних, унікальних, спільних для A і C, від'ємних без повторень.
    int ar, ac, br, bc, cr, cc;

    cout << "A rows cols: ";
    cin >> ar >> ac;
    cout << "B rows cols: ";
    cin >> br >> bc;
    cout << "C rows cols: ";
    cin >> cr >> cc;

    int** a = new int* [ar];
    int** b = new int* [br];
    int** c = new int* [cr];

    for (int i = 0; i < ar; i++)
    {
        a[i] = new int[ac];
    }
    for (int i = 0; i < br; i++)
    {
        b[i] = new int[bc];
    }
    for (int i = 0; i < cr; i++)
    {
        c[i] = new int[cc];
    }

    cout << "A:\n";
    for (int i = 0; i < ar; i++)
    {
        for (int j = 0; j < ac; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "B:\n";
    for (int i = 0; i < br; i++)
    {
        for (int j = 0; j < bc; j++)
        {
            cin >> b[i][j];
        }
    }

    cout << "C:\n";
    for (int i = 0; i < cr; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            cin >> c[i][j];
        }
    }

    int total = ar * ac + br * bc + cr * cc;
    int* common = new int[total];
    int* unique = new int[total];
    int* acCommon = new int[total];
    int* negative = new int[total];
    int commonSize = 0;
    int uniqueSize = 0;
    int acSize = 0;
    int negativeSize = 0;

    for (int i = 0; i < ar; i++)
    {
        for (int j = 0; j < ac; j++)
        {
            int value = a[i][j];

            if (inMatrix(b, br, bc, value) && inMatrix(c, cr, cc, value) && !exists(common, commonSize, value))
            {
                common[commonSize] = value;
                commonSize++;
            }

            if (countInAll(a, ar, ac, b, br, bc, c, cr, cc, value) == 1 && !exists(unique, uniqueSize, value))
            {
                unique[uniqueSize] = value;
                uniqueSize++;
            }

            if (inMatrix(c, cr, cc, value) && !exists(acCommon, acSize, value))
            {
                acCommon[acSize] = value;
                acSize++;
            }

            if (value < 0 && !exists(negative, negativeSize, value))
            {
                negative[negativeSize] = value;
                negativeSize++;
            }
        }
    }

    for (int i = 0; i < br; i++)
    {
        for (int j = 0; j < bc; j++)
        {
            int value = b[i][j];

            if (countInAll(a, ar, ac, b, br, bc, c, cr, cc, value) == 1 && !exists(unique, uniqueSize, value))
            {
                unique[uniqueSize] = value;
                uniqueSize++;
            }

            if (value < 0 && !exists(negative, negativeSize, value))
            {
                negative[negativeSize] = value;
                negativeSize++;
            }
        }
    }

    for (int i = 0; i < cr; i++)
    {
        for (int j = 0; j < cc; j++)
        {
            int value = c[i][j];

            if (countInAll(a, ar, ac, b, br, bc, c, cr, cc, value) == 1 && !exists(unique, uniqueSize, value))
            {
                unique[uniqueSize] = value;
                uniqueSize++;
            }

            if (value < 0 && !exists(negative, negativeSize, value))
            {
                negative[negativeSize] = value;
                negativeSize++;
            }
        }
    }

    cout << "common ABC: ";
    for (int i = 0; i < commonSize; i++)
    {
        cout << common[i] << " ";
    }

    cout << "\nunique: ";
    for (int i = 0; i < uniqueSize; i++)
    {
        cout << unique[i] << " ";
    }

    cout << "\ncommon AC: ";
    for (int i = 0; i < acSize; i++)
    {
        cout << acCommon[i] << " ";
    }

    cout << "\nnegative: ";
    for (int i = 0; i < negativeSize; i++)
    {
        cout << negative[i] << " ";
    }

    for (int i = 0; i < ar; i++)
    {
        delete[] a[i];
    }
    for (int i = 0; i < br; i++)
    {
        delete[] b[i];
    }
    for (int i = 0; i < cr; i++)
    {
        delete[] c[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;
    delete[] common;
    delete[] unique;
    delete[] acCommon;
    delete[] negative;

}
