#include <iostream>
using namespace std;

int main()
{
    //task1 //Завдання 1 Написати програму "довідник". Масиви мобільних і домашніх номерів. Меню: сортування, список, вихід.
    /*string names[5] = { "Anton", "Dima", "Oleg", "Max", "Ivan" };
    int mobile[5] = { 5033, 5011, 5099, 5022, 5044 };
    int home[5] = { 121, 105, 144, 111, 130 };
    int choice;

    do
    {
        cout << "1-sort mobile\n";
        cout << "2-sort home\n";
        cout << "3-list\n";
        cout << "0-exit\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4 - i; j++)
                {
                    if (mobile[j] > mobile[j + 1])
                    {
                        int temp = mobile[j];
                        mobile[j] = mobile[j + 1];
                        mobile[j + 1] = temp;

                        temp = home[j];
                        home[j] = home[j + 1];
                        home[j + 1] = temp;

                        string tempName = names[j];
                        names[j] = names[j + 1];
                        names[j + 1] = tempName;
                    }
                }
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4 - i; j++)
                {
                    if (home[j] > home[j + 1])
                    {
                        int temp = mobile[j];
                        mobile[j] = mobile[j + 1];
                        mobile[j + 1] = temp;

                        temp = home[j];
                        home[j] = home[j + 1];
                        home[j + 1] = temp;

                        string tempName = names[j];
                        names[j] = names[j + 1];
                        names[j + 1] = tempName;
                    }
                }
            }
        }
        else if (choice == 3)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << names[i] << " " << mobile[i] << " " << home[i] << '\n';
            }
        }
    } while (choice != 0);*/

    //task2 //Завдання 2 Сортування масиву удосконаленим бульбашковим методом.
    /*int arr[10] = { 5, 1, 9, 3, 7, 2, 8, 4, 6, 0 };
    bool swapped;

    for (int i = 0; i < 9; i++)
    {
        swapped = false;

        for (int j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }*/

    //task3 //Завдання 3 Відсортувати стопку оладок знизу вгору за зменшенням радіуса мінімальними переворотами.
    int n;
    int arr[20];
    int count = 0;

    cout << "n: ";
    cin >> n;

    cout << "from bottom to top:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int pos = 0; pos < n - 1; pos++)
    {
        int maxIndex = pos;

        for (int i = pos + 1; i < n; i++)
        {
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i;
            }
        }

        if (maxIndex != pos)
        {
            if (maxIndex != n - 1)
            {
                for (int left = maxIndex, right = n - 1; left < right; left++, right--)
                {
                    int temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;
                }
                count++;
            }

            for (int left = pos, right = n - 1; left < right; left++, right--)
            {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
            count++;
        }
    }

    cout << "result:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nturns: " << count;

}
