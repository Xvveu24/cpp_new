#include <iostream>
using namespace std;

//task1 Написати функцію, що реалізує алгоритм лінійного пошуку заданого ключа в одновимірному масиві.
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

//task2 Написати функцію, що реалізує алгоритм бінарного пошуку заданого ключа в одновимірному масиві.
int binarySearch(int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

//task3 Написати функцію для переведення числа, записаного в двійковому вигляді, в десяткове подання.
int binaryToDecimal(char binary[])
{
    int decimal = 0;
    int len = 0;
    
    while (binary[len] != '\0')
    {
        len++;
    }
    
    for (int i = 0; i < len; i++)
    {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    
    return decimal;
}

int main()
{
    //task1
    int arr1[10] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 10};
    int key1 = 7;
    
    cout << "Масив: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    int index1 = linearSearch(arr1, 10, key1);
    if (index1 != -1)
    {
        cout << "Ключ " << key1 << " знайдено на позицiї " << index1 << endl;
    }
    else
    {
        cout << "Ключ " << key1 << " не знайдено" << endl;
    }
    
    //task2
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key2 = 7;
    
    cout << "\nВiдсортований масив: ";
    for (int i = 0; i < 10; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    int index2 = binarySearch(arr2, 10, key2);
    if (index2 != -1)
    {
        cout << "Ключ " << key2 << " знайдено на позицiї " << index2 << endl;
    }
    else
    {
        cout << "Ключ " << key2 << " не знайдено" << endl;
    }
    
    //task3
    char binary1[5] = "1010";
    char binary2[5] = "1111";
    char binary3[9] = "10000000";
    
    cout << "\nДвiйкове: " << binary1 << " -> Десяткове: " << binaryToDecimal(binary1) << endl;
    cout << "Двiйкове: " << binary2 << " -> Десяткове: " << binaryToDecimal(binary2) << endl;
    cout << "Двiйкове: " << binary3 << " -> Десяткове: " << binaryToDecimal(binary3) << endl;
    
    return 0;
}