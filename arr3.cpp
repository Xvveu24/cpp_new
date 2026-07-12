#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//task1 У двовимірному масиві цілих чисел порахувати: Суму всіх елементів масиву; Середнє арифметичне всіх елементів масиву; Мінімальний елемент; Максимальний елемент.
void task1()
{
    int rows, cols;
    cout << "Введiть кiлькiсть рядкiв: ";
    cin >> rows;
    cout << "Введiть кiлькiсть стовпцiв: ";
    cin >> cols;

    int** A = new int*[rows];
    for (int i = 0; i < rows; i++)
        A[i] = new int[cols];

    cout << "Введiть елементи масиву:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> A[i][j];

    int sum = 0, minVal = A[0][0], maxVal = A[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            sum += A[i][j];
            if (A[i][j] < minVal) minVal = A[i][j];
            if (A[i][j] > maxVal) maxVal = A[i][j];
        }

    double avg = (double)sum / (rows * cols);

    cout << "Сума: " << sum << endl;
    cout << "Середнє: " << avg << endl;
    cout << "Мiнiмум: " << minVal << endl;
    cout << "Максимум: " << maxVal << endl;

    for (int i = 0; i < rows; i++) delete[] A[i];
    delete[] A;
}

//task2 У двовимірному масиві цілих чисел порахувати суму елементів: У кожному рядку; У кожному стовпчику; Одночасно по всіх рядках і всіх стовпцях. Оформити наступним чином: (таблиця з сумами)
void task2()
{
    int rows, cols;
    cout << "Введiть кiлькiсть рядкiв: ";
    cin >> rows;
    cout << "Введiть кiлькiсть стовпцiв: ";
    cin >> cols;

    int** A = new int*[rows];
    for (int i = 0; i < rows; i++)
        A[i] = new int[cols];

    cout << "Введiть елементи масиву:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> A[i][j];

    int* rowSum = new int[rows]();
    int* colSum = new int[cols]();
    int total = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            rowSum[i] += A[i][j];
            colSum[j] += A[i][j];
            total += A[i][j];
        }

    cout << "\nТаблиця з сумами:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(5) << A[i][j] << " ";
        cout << "| " << rowSum[i] << endl;
    }
    for (int j = 0; j < cols; j++)
        cout << "-----";
    cout << endl;
    for (int j = 0; j < cols; j++)
        cout << setw(5) << colSum[j] << " ";
    cout << "| " << total << endl;

    delete[] rowSum;
    delete[] colSum;
    for (int i = 0; i < rows; i++) delete[] A[i];
    delete[] A;
}

//task3 Напишіть програму, в якій оголошується масив розміром 5х10 і масив розміром 5х5. Перший масив заповнюється випадковими числами у діапазоні від 0 до 50. Другий масив заповнюється за таким принципом: перший елемент другого масиву дорівнює сумі першого і другого елемента першого масиву, другий елемент другого масиву дорівнює сумі третього і четвертого елемента першого масиву.
void task3()
{
    const int ROWS = 5;
    const int COLS1 = 10;
    const int COLS2 = 5;

    int A[ROWS][COLS1];
    int B[ROWS][COLS2];

    srand(time(0));
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS1; j++)
            A[i][j] = rand() % 51;

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS2; j++)
            B[i][j] = A[i][2 * j] + A[i][2 * j + 1];

    cout << "Масив A (5x10):\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS1; j++)
            cout << setw(4) << A[i][j] << " ";
        cout << endl;
    }

    cout << "\nМасив B (5x5) - суми пар сусіднiх елементiв з A:\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS2; j++)
            cout << setw(4) << B[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\nВиберiть завдання (1-3), 0 - вихiд: ";
        cin >> choice;
        switch (choice)
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: cout << "Вихiд.\n"; break;
        default: cout << "Невiрний вибiр.\n";
        }
    } while (choice != 0);

    return 0;
}