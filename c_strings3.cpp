#include <iostream>
using namespace std;

int mystrcmp(const char* str1, const char* str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }

        i++;
    }

    if (str1[i] == str2[i])
    {
        return 0;
    }
    else if (str1[i] > str2[i])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int StringToNumber(char* str)
{
    int number = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    while (str[i] != '\0')
    {
        number = number * 10 + (str[i] - '0');
        i++;
    }

    return number * sign;
}

char* NumberToString(int number)
{
    static char str[20];
    char temp[20];
    int i = 0;
    int j = 0;
    int sign = 0;

    if (number == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    if (number < 0)
    {
        sign = 1;
        number = -number;
    }

    while (number > 0)
    {
        temp[i] = number % 10 + '0';
        number = number / 10;
        i++;
    }

    if (sign == 1)
    {
        str[j] = '-';
        j++;
    }

    for (int k = i - 1; k >= 0; k--)
    {
        str[j] = temp[k];
        j++;
    }

    str[j] = '\0';

    return str;
}

char* Uppercase(char* str1)
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 'a' && str1[i] <= 'z')
        {
            str1[i] = str1[i] - 32;
        }
    }

    return str1;
}

char* Lowercase(char* str1)
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 'A' && str1[i] <= 'Z')
        {
            str1[i] = str1[i] + 32;
        }
    }

    return str1;
}

char* mystrrev(char* str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    return str;
}

int main()
{
    //task1 //Завдання 1 Користувач вводить рядок. Визначити кількість літер, цифр та інших символів.
    /*char str[100];
    int letters = 0;
    int digits = 0;
    int other = 0;

    cout << "text: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            letters++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
        else
        {
            other++;
        }
    }

    cout << "letters: " << letters;
    cout << "\ndigits: " << digits;
    cout << "\nother: " << other;*/

    //task2 //Завдання 2 Доповнити бібліотеку функцій для C-рядків.
    char str1[100] = "Hello";
    char str2[100] = "12345";
    char str3[100] = "World";

    cout << "cmp: " << mystrcmp(str1, str3) << '\n';
    cout << "num: " << StringToNumber(str2) << '\n';
    cout << "str: " << NumberToString(-345) << '\n';

    cout << "upper: " << Uppercase(str1) << '\n';
    cout << "lower: " << Lowercase(str1) << '\n';
    cout << "rev: " << mystrrev(str3);

}
