#include <iostream>
using namespace std;

//task5 //Завдання 5 Створити бібліотеку функцій для роботи з C-рядками.
int mystrlen(const char* str)
{
    int len = 0;

    while (str[len] != '\0')
    {
        len++;
    }

    return len;
}

char* mystrcpy(char* str1, const char* str2)
{
    int i = 0;

    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }

    str1[i] = '\0';

    return str1;
}

char* mystrcat(char* str1, const char* str2)
{
    int i = mystrlen(str1);
    int j = 0;

    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';

    return str1;
}

char* mystrchr(char* str, char s)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == s)
        {
            return &str[i];
        }
    }

    return 0;
}

char* mystrstr(char* str1, char* str2)
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        int j = 0;

        while (str2[j] != '\0' && str1[i + j] == str2[j])
        {
            j++;
        }

        if (str2[j] == '\0')
        {
            return &str1[i];
        }
    }

    return 0;
}

int main()
{
    //task1 //Завдання 1 Дано рядок символів. Замінити в ньому всі пробіли на табуляції.
    /*char str[100];

    cout << "text: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '\t';
        }
    }

    cout << str;*/

    //task2 //Завдання 2 Дано рядок символів. Визначити кількість літер, цифр та інших символів.
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

    //task3 //Завдання 3 Підрахувати кількість слів у введеному реченні.
    /*char str[100];
    int words = 0;
    bool inWord = false;

    cout << "text: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && inWord == false)
        {
            words++;
            inWord = true;
        }
        else if (str[i] == ' ')
        {
            inWord = false;
        }
    }

    cout << "words: " << words;*/

    //task4 //Завдання 4 Дано рядок символів. Перевірити чи є цей рядок паліндромом.
    /*char str[100];
    bool pal = true;

    cout << "text: ";
    cin.getline(str, 100);

    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            pal = false;
        }
    }

    if (pal == true)
    {
        cout << "palindrome";
    }
    else
    {
        cout << "not palindrome";
    }*/

    char str1[100] = "hello";
    char str2[100] = " world";
    char findText[20] = "lo";

    cout << "len: " << mystrlen(str1) << '\n';

    mystrcat(str1, str2);
    cout << "cat: " << str1 << '\n';

    mystrcpy(str2, "test");
    cout << "copy: " << str2 << '\n';

    if (mystrchr(str1, 'w') != 0)
    {
        cout << "char found\n";
    }
    else
    {
        cout << "char not found\n";
    }

    if (mystrstr(str1, findText) != 0)
    {
        cout << "text found";
    }
    else
    {
        cout << "text not found";
    }

}
