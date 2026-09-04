#include <iostream>
#include <cstring>
using namespace std;

//task1 //Завдання 1 Написати функцію, яка видаляє з рядка символ із заданим номером.
/*void deleteByIndex(char str[], int index)
{
    int len = strlen(str);

    if (index < 0 || index >= len)
    {
        return;
    }

    for (int i = index; i < len; i++)
    {
        str[i] = str[i + 1];
    }
}*/

//task2 //Завдання 2 Написати функцію, яка видаляє з рядка всі входження заданого символу.
/*void deleteSymbol(char str[], char symbol)
{
    int pos = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != symbol)
        {
            str[pos] = str[i];
            pos++;
        }
    }

    str[pos] = '\0';
}*/

//task3 //Завдання 3 Написати функцію, яка вставляє в рядок у вказану позицію заданий символ.
/*void insertSymbol(char str[], int index, char symbol)
{
    int len = strlen(str);

    if (index < 0 || index > len)
    {
        return;
    }

    for (int i = len; i >= index; i--)
    {
        str[i + 1] = str[i];
    }

    str[index] = symbol;
}*/

int main()
{
    //task4 //Завдання 4 Замінити всі крапки "." у рядку на знаки оклику "!".
    /*char str[100];

    cout << "text: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            str[i] = '!';
        }
    }

    cout << str;*/

    //task5 //Завдання 5 Користувач вводить рядок символів і шуканий символ. Порахувати скільки разів він зустрічається.
    char str[100];
    char symbol;
    int count = 0;

    cout << "text: ";
    cin.getline(str, 100);

    cout << "symbol: ";
    cin >> symbol;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == symbol)
        {
            count++;
        }
    }

    cout << "count: " << count;

}
