#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//task1 //Завдання 1 Переписати в новий файл слова довжиною не менше семи символів.
/*int main()
{
    ifstream input("input.txt");
    ofstream output("result.txt");
    string word;

    while (input >> word)
    {
        if (word.length() >= 7)
        {
            output << word << " ";
        }
    }
}*/

//task2 //Завдання 2 Переписати рядки в інший файл у тому самому порядку.
/*int main()
{
    ifstream input("input.txt");
    ofstream output("result.txt");
    string line;

    while (getline(input, line))
    {
        output << line << '\n';
    }
}*/

//task3 //Завдання 3 Переписати рядки в інший файл у зворотному порядку.
/*int main()
{
    ifstream input("input.txt");
    ofstream output("result.txt");
    vector<string> lines;
    string line;

    while (getline(input, line))
    {
        lines.push_back(line);
    }

    for (int i = lines.size() - 1; i >= 0; i--)
    {
        output << lines[i] << '\n';
    }
}*/

int main()
{
    //task4 //Додати рядок з 12 рисок після останнього рядка без пробілів.
    ifstream input("input.txt");
    ofstream output("result.txt");

    if (!input.is_open() || !output.is_open())
    {
        cout << "file error";
        return 0;
    }

    vector<string> lines;
    string line;

    while (getline(input, line))
    {
        lines.push_back(line);
    }

    int insertAfter = -1;

    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].find(' ') == string::npos)
        {
            insertAfter = i;
        }
    }

    for (int i = 0; i < lines.size(); i++)
    {
        output << lines[i] << '\n';

        if (i == insertAfter)
        {
            output << "------------\n";
        }
    }

    if (insertAfter == -1)
    {
        output << "------------\n";
    }

    cout << "saved: result.txt";
}
