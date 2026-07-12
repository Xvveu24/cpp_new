#include <iostream>
using namespace std;

//task1 Дано два масиви: А[M] і B[N] (M і N вводяться з клавіатури). Необхідно створити третій масив мінімально можливого розміру, у якому потрібно зібрати елементи обох масивів.
int* combineArrays(int* A, int M, int* B, int N, int& sizeC)
{
    sizeC = M + N;
    int* C = new int[sizeC];
    for (int i = 0; i < M; i++) C[i] = A[i];
    for (int i = 0; i < N; i++) C[M + i] = B[i];
    return C;
}

//task2 Дано два масиви: А[M] і B[N] (M і N вводяться з клавіатури). Необхідно створити третій масив мінімально можливого розміру, в якому потрібно зібрати спільні елементи двох масивів без повторень.
bool exists(int* arr, int size, int val)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == val) return true;
    return false;
}

int* commonElements(int* A, int M, int* B, int N, int& sizeC)
{
    int maxSize = (M < N) ? M : N;
    int* temp = new int[maxSize];
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        if (exists(B, N, A[i]) && !exists(temp, cnt, A[i]))
        {
            temp[cnt++] = A[i];
        }
    }
    int* C = new int[cnt];
    for (int i = 0; i < cnt; i++) C[i] = temp[i];
    delete[] temp;
    sizeC = cnt;
    return C;
}

//task3 Дано масив: А[M] (M вводиться з клавіатури). Необхідно видалити з масиву парні або непарні значення. Користувач вводить дані в масив, а також за допомогою меню вирішує, що потрібно видалити.
int* removeEvenOdd(int* A, int& M, int choice)
{
    int newSize = 0;
    for (int i = 0; i < M; i++)
    {
        if (choice == 1) // видалити парні
        {
            if (A[i] % 2 != 0) newSize++;
        }
        else if (choice == 2) // видалити непарні
        {
            if (A[i] % 2 == 0) newSize++;
        }
    }
    int* B = new int[newSize];
    int idx = 0;
    for (int i = 0; i < M; i++)
    {
        if (choice == 1 && A[i] % 2 != 0) B[idx++] = A[i];
        else if (choice == 2 && A[i] % 2 == 0) B[idx++] = A[i];
    }
    delete[] A;
    M = newSize;
    return B;
}

int main()
{
    int task;
    cout << "Виберiть завдання (1-3): ";
    cin >> task;

    if (task == 1)
    {
        int M, N;
        cout << "Розмiр A: "; cin >> M;
        int* A = new int[M];
        cout << "Елементи A: ";
        for (int i = 0; i < M; i++) cin >> A[i];

        cout << "Розмiр B: "; cin >> N;
        int* B = new int[N];
        cout << "Елементи B: ";
        for (int i = 0; i < N; i++) cin >> B[i];

        int sizeC;
        int* C = combineArrays(A, M, B, N, sizeC);

        cout << "Об'єднаний масив: ";
        for (int i = 0; i < sizeC; i++) cout << C[i] << " ";
        cout << endl;

        delete[] A; delete[] B; delete[] C;
    }
    else if (task == 2)
    {
        int M, N;
        cout << "Розмiр A: "; cin >> M;
        int* A = new int[M];
        cout << "Елементи A: ";
        for (int i = 0; i < M; i++) cin >> A[i];

        cout << "Розмiр B: "; cin >> N;
        int* B = new int[N];
        cout << "Елементи B: ";
        for (int i = 0; i < N; i++) cin >> B[i];

        int sizeC;
        int* C = commonElements(A, M, B, N, sizeC);

        cout << "Спiльнi елементи без повторень: ";
        for (int i = 0; i < sizeC; i++) cout << C[i] << " ";
        cout << endl;

        delete[] A; delete[] B; delete[] C;
    }
    else if (task == 3)
    {
        int M;
        cout << "Розмiр A: "; cin >> M;
        int* A = new int[M];
        cout << "Елементи A: ";
        for (int i = 0; i < M; i++) cin >> A[i];

        int choice;
        cout << "Що видалити? (1 - парнi, 2 - непарнi): ";
        cin >> choice;

        A = removeEvenOdd(A, M, choice);

        cout << "Результат: ";
        for (int i = 0; i < M; i++) cout << A[i] << " ";
        cout << endl;

        delete[] A;
    }
    else
    {
        cout << "Невiрний вибiр" << endl;
    }

    return 0;
}