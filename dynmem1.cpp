#include <iostream>
#include <cmath>
using namespace std;

//Завдання 1 Написати такі функції для роботи з динамічним масивом: Функція виділення динамічної пам'яті. Функція ініціалізації динамічного масиву. Функція друку динамічного масиву. Функція видалення динамічного масиву. Функція додавання елемента в кінець масиву. Функція вставки елемента за вказаним індексом. Функція видалення елемента за вказаним індексом.
int* allocMem(int size)
{
    return new int[size];
}

void initArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 41 - 20;
    }
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void delArr(int* arr)
{
    delete[] arr;
}

int* addEl(int* arr, int& size, int val)
{
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[size] = val;
    size++;
    delete[] arr;
    return newArr;
}

int* insertEl(int* arr, int& size, int idx, int val)
{
    if (idx < 0 || idx > size)
    {
        cout << "bad index\n";
        return arr;
    }
    int* newArr = new int[size + 1];
    for (int i = 0; i < idx; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[idx] = val;
    for (int i = idx; i < size; i++)
    {
        newArr[i + 1] = arr[i];
    }
    size++;
    delete[] arr;
    return newArr;
}

int* delEl(int* arr, int& size, int idx)
{
    if (idx < 0 || idx >= size)
    {
        cout << "bad index\n";
        return arr;
    }
    int* newArr = new int[size - 1];
    for (int i = 0; i < idx; i++)
    {
        newArr[i] = arr[i];
    }
    for (int i = idx + 1; i < size; i++)
    {
        newArr[i - 1] = arr[i];
    }
    size--;
    delete[] arr;
    return newArr;
}

//Завдання 2 Написати функцію, яка отримує покажчик на динамічний масив і його розмір. Функція повинна видалити з масиву всі прості числа і повернути покажчик на новий динамічний масив.
bool isPrime(int x)
{
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int& size)
{
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (!isPrime(arr[i])) cnt++;
    }
    if (cnt == 0)
    {
        delete[] arr;
        size = 0;
        return NULL;
    }
    int* newArr = new int[cnt];
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (!isPrime(arr[i]))
        {
            newArr[k++] = arr[i];
        }
    }
    delete[] arr;
    size = cnt;
    return newArr;
}

//Завдання 3 Написати функцію, яка отримує покажчик на статичний масив і його розмір. Функція розподіляє додатні, від'ємні та нульові елементи в окремі динамічні масиви.
void splitArr(int* src, int n, int*& pos, int& pn, int*& neg, int& nn, int*& zer, int& zn)
{
    pn = nn = zn = 0;
    for (int i = 0; i < n; i++)
    {
        if (src[i] > 0) pn++;
        else if (src[i] < 0) nn++;
        else zn++;
    }
    pos = new int[pn];
    neg = new int[nn];
    zer = new int[zn];
    int pi = 0, ni = 0, zi = 0;
    for (int i = 0; i < n; i++)
    {
        if (src[i] > 0) pos[pi++] = src[i];
        else if (src[i] < 0) neg[ni++] = src[i];
        else zer[zi++] = src[i];
    }
}

int main()
{
    srand(time(0));
    //task1
    int n = 5;
    int* a = allocMem(n);
    initArr(a, n);
    printArr(a, n);
    a = addEl(a, n, 99);
    printArr(a, n);
    a = insertEl(a, n, 2, 77);
    printArr(a, n);
    a = delEl(a, n, 3);
    printArr(a, n);
    delArr(a);

    //task2
    int n2 = 10;
    int* b = allocMem(n2);
    for (int i = 0; i < n2; i++) b[i] = rand() % 30 + 1;
    printArr(b, n2);
    b = removePrimes(b, n2);
    if (b) printArr(b, n2);
    else cout << "empty\n";
    if (b) delArr(b);

    //task3
    int src[10] = {5, -3, 0, 7, -8, 0, 12, -15, 0, 4};
    int* pos, *neg, *zer;
    int pn, nn, zn;
    splitArr(src, 10, pos, pn, neg, nn, zer, zn);
    printArr(pos, pn);
    printArr(neg, nn);
    printArr(zer, zn);
    delArr(pos);
    delArr(neg);
    delArr(zer);

    return 0;
}