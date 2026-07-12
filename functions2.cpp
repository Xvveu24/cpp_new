#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//task1 //Завдання 1 Функція сортує масив за зростанням або спаданням залежно від третього параметра.
/*void sortArr(int arr[], int size, bool desc = false)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if ((desc == false && arr[j] > arr[j + 1]) || (desc == true && arr[j] < arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}*/

//task2 //Завдання 2 Функція сортує першу половину масиву за спаданням, другу - за зростанням методом вставок.
/*void sortHalf(int arr[], int size)
{
    for (int i = 1; i < size / 2; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    for (int i = size / 2 + 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= size / 2 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}*/

void sortBetweenNeg(int arr[], int size)
{
    int firstNeg = -1;
    int lastNeg = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (firstNeg == -1)
            {
                firstNeg = i;
            }

            lastNeg = i;
        }
    }

    if (firstNeg == -1 || firstNeg == lastNeg)
    {
        cout << "not enough negatives\n";
        return;
    }

    for (int i = firstNeg + 1; i < lastNeg - 1; i++)
    {
        for (int j = firstNeg + 1; j < lastNeg - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    //task3 //Завдання 3 Знайти крайні від'ємні елементи і відсортувати елементи між ними.
    srand(time(0));

    int arr[10];

    cout << "before: ";
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 41 - 20;
        cout << arr[i] << " ";
    }

    sortBetweenNeg(arr, 10);

    cout << "\nafter: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

}
