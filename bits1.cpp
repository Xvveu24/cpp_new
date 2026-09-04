#include <iostream>
using namespace std;

char* ToBinary(int number)
{
    static char str[33];
    char temp[33];
    int pos = 0;

    if (number == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    while (number > 0)
    {
        temp[pos] = number % 2 + '0';
        number = number / 2;
        pos++;
    }

    for (int i = 0; i < pos; i++)
    {
        str[i] = temp[pos - 1 - i];
    }

    str[pos] = '\0';

    return str;
}

char* ToHex(int number)
{
    static char str[20];
    char temp[20];
    int pos = 0;

    if (number == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    while (number > 0)
    {
        int digit = number % 16;

        if (digit < 10)
        {
            temp[pos] = digit + '0';
        }
        else
        {
            temp[pos] = digit - 10 + 'A';
        }

        number = number / 16;
        pos++;
    }

    for (int i = 0; i < pos; i++)
    {
        str[i] = temp[pos - 1 - i];
    }

    str[pos] = '\0';

    return str;
}

int BinaryToDecimal(char* str)
{
    int number = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        number = number * 2 + (str[i] - '0');
    }

    return number;
}

int HexToDecimal(char* str)
{
    int number = 0;
    int digit;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            digit = str[i] - '0';
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            digit = str[i] - 'A' + 10;
        }
        else
        {
            digit = str[i] - 'a' + 10;
        }

        number = number * 16 + digit;
    }

    return number;
}

int main()
{
    int number;
    char binary[33];
    char hex[20];

    cout << "number: ";
    cin >> number;

    cout << "bin: " << ToBinary(number) << '\n';
    cout << "hex: " << ToHex(number) << '\n';

    cout << "bin text: ";
    cin >> binary;
    cout << "dec: " << BinaryToDecimal(binary) << '\n';

    cout << "hex text: ";
    cin >> hex;
    cout << "dec: " << HexToDecimal(hex);

}
