#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//task1 //Завдання 1 Порівняти рядки двох текстових файлів.
/*int main()
{
    ifstream file1("first.txt");
    ifstream file2("second.txt");
    string line1, line2;
    int number = 1;
    bool same = true;

    while (getline(file1, line1) && getline(file2, line2))
    {
        if (line1 != line2)
        {
            cout << "file1: " << line1 << '\n';
            cout << "file2: " << line2 << '\n';
            same = false;
        }
        number++;
    }

    if (same)
    {
        cout << "files are same";
    }
}*/

//task2 //Завдання 2 Порахувати символи, рядки, голосні, приголосні та цифри у файлі.
/*int main()
{
    ifstream input("input.txt");
    ofstream output("stats.txt");
    char symbol;
    int chars = 0, lines = 0, vowels = 0, consonants = 0, digits = 0;

    while (input.get(symbol))
    {
        chars++;

        if (symbol == '\n')
        {
            lines++;
        }
        else if (symbol >= '0' && symbol <= '9')
        {
            digits++;
        }
        else if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z')
        {
            if (symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' || symbol == 'u' ||
                symbol == 'A' || symbol == 'E' || symbol == 'I' || symbol == 'O' || symbol == 'U')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    output << "chars: " << chars << '\n';
    output << "lines: " << lines << '\n';
    output << "vowels: " << vowels << '\n';
    output << "consonants: " << consonants << '\n';
    output << "digits: " << digits;
}*/

int main()
{
    //task3 //Завдання 3 Зашифрувати текстовий файл шифром Цезаря і записати результат в інший файл.
    ifstream input("input.txt");
    ofstream output("encrypted.txt");

    if (!input.is_open() || !output.is_open())
    {
        cout << "file error";
        return 0;
    }

    const string lower = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
    const string upper = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
    const string engLower = "abcdefghijklmnopqrstuvwxyz";
    const string engUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string text;
    int key;

    cout << "key: ";
    cin >> key;

    while (getline(input, text))
    {
        for (int i = 0; i < text.length(); i++)
        {
            string current = text.substr(i, 2);
            string alphabet;

            if (lower.find(current) != string::npos)
            {
                alphabet = lower;
            }
            else if (upper.find(current) != string::npos)
            {
                alphabet = upper;
            }

            if (alphabet != "")
            {
                int pos = alphabet.find(current) / 2;
                int letters = alphabet.length() / 2;
                int newPos = (pos + key) % letters;

                if (newPos < 0)
                {
                    newPos = newPos + letters;
                }

                text.replace(i, 2, alphabet.substr(newPos * 2, 2));
                i++;
            }
            else if (engLower.find(text[i]) != string::npos || engUpper.find(text[i]) != string::npos)
            {
                alphabet = engLower;

                if (engUpper.find(text[i]) != string::npos)
                {
                    alphabet = engUpper;
                }

                int pos = alphabet.find(text[i]);
                int newPos = (pos + key) % 26;

                if (newPos < 0)
                {
                    newPos = newPos + 26;
                }

                text[i] = alphabet[newPos];
            }
        }

        output << text << '\n';
    }

    cout << "saved: encrypted.txt";
}
