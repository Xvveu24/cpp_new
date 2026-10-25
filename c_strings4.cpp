#include <iostream>
#include <string>
using namespace std;

int main()
{
    // task1
    /*string path;
    cout << "Enter file path: ";
    getline(cin, path);

    size_t slashPosition = path.rfind('\\');
    size_t forwardSlashPosition = path.rfind('/');

    if (forwardSlashPosition != string::npos &&
        (slashPosition == string::npos || forwardSlashPosition > slashPosition))
    {
        slashPosition = forwardSlashPosition;
    }

    string fileName = path.substr(slashPosition == string::npos ? 0 : slashPosition + 1);
    size_t dotPosition = fileName.rfind('.');

    if (dotPosition == string::npos || dotPosition == 0)
    {
        cout << "Name: " << fileName << '\n';
        cout << "Extension: none\n";
    }
    else
    {
        string name = fileName.substr(0, dotPosition);
        string extension = fileName.substr(dotPosition + 1);

        cout << "Name: " << name << '\n';
        cout << "Extension: " << extension << '\n';
    }*/

    // task2
    string text;
    string word;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter word: ";
    getline(cin, word);

    if (word.empty())
    {
        cout << "Word cannot be empty.\n";
        return 0;
    }

    int count = 0;
    size_t startPosition = 0;
    size_t foundPosition = text.find(word, startPosition);

    while (foundPosition != string::npos)
    {
        count++;
        startPosition = foundPosition + word.length();
        foundPosition = text.find(word, startPosition);
    }

    cout << "Found: " << count << '\n';
}
