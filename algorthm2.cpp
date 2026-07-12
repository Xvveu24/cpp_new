#include <iostream>
using namespace std;

int main()
{
    //task1 //Завдання 1 Обрати два алгоритми сортування і реалізувати. Тут: selection sort та insertion sort.
    /*int arr1[10] = { 7, 2, 9, 1, 5, 8, 3, 6, 4, 0 };
    int arr2[10] = { 7, 2, 9, 1, 5, 8, 3, 6, 4, 0 };

    for (int i = 0; i < 9; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < 10; j++)
        {
            if (arr1[j] < arr1[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr1[i];
        arr1[i] = arr1[minIndex];
        arr1[minIndex] = temp;
    }

    for (int i = 1; i < 10; i++)
    {
        int key = arr2[i];
        int j = i - 1;

        while (j >= 0 && arr2[j] > key)
        {
            arr2[j + 1] = arr2[j];
            j--;
        }

        arr2[j + 1] = key;
    }

    cout << "selection: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\ninsertion: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }*/

    //task2 //Завдання 2 Програма "успішність". Оцінки, перескладання, перевірка стипендії.
    /*double marks[10];
    int choice;

    for (int i = 0; i < 10; i++)
    {
        cout << "mark " << i + 1 << ": ";
        cin >> marks[i];
    }

    do
    {
        cout << "\n1-show\n";
        cout << "2-change\n";
        cout << "3-scholarship\n";
        cout << "0-exit\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                cout << marks[i] << " ";
            }
        }
        else if (choice == 2)
        {
            int index;
            double mark;

            cout << "number: ";
            cin >> index;
            cout << "new mark: ";
            cin >> mark;

            if (index >= 1 && index <= 10)
            {
                marks[index - 1] = mark;
            }
        }
        else if (choice == 3)
        {
            double sum = 0;

            for (int i = 0; i < 10; i++)
            {
                sum = sum + marks[i];
            }

            double average = sum / 10;

            cout << "avg: " << average << '\n';

            if (average >= 10.7)
            {
                cout << "yes";
            }
            else
            {
                cout << "no";
            }
        }
    } while (choice != 0);*/

    //task3 //Завдання 3 Сортування одновимірного масиву методом швидкого сортування.
    /*int arr[10] = { 5, 1, 9, 3, 7, 2, 8, 4, 6, 0 };
    int left[100], right[100];
    int top = 0;

    left[top] = 0;
    right[top] = 9;
    top++;

    while (top > 0)
    {
        top--;

        int l = left[top];
        int r = right[top];
        int i = l;
        int j = r;
        int pivot = arr[(l + r) / 2];

        while (i <= j)
        {
            while (arr[i] < pivot)
            {
                i++;
            }
            while (arr[j] > pivot)
            {
                j--;
            }

            if (i <= j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        if (l < j)
        {
            left[top] = l;
            right[top] = j;
            top++;
        }
        if (i < r)
        {
            left[top] = i;
            right[top] = r;
            top++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }*/

    //task4 //Завдання 4 Відсортувати частину масиву залежно від середнього, іншу частину розташувати у зворотному порядку.
    int arr[12] = { 4, -2, 7, 1, 9, -3, 5, 0, 8, -6, 2, 10 };
    int n = 12;
    double sum = 0;

    cout << "before: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        sum = sum + arr[i];
    }

    double average = sum / n;
    int sortEnd;

    if (average > 0)
    {
        sortEnd = n * 2 / 3;
    }
    else
    {
        sortEnd = n / 3;
    }

    for (int i = 0; i < sortEnd - 1; i++)
    {
        for (int j = 0; j < sortEnd - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int left = sortEnd, right = n - 1; left < right; left++, right--)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }

    cout << "\na: " << average;
    cout << "\nafter: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}
