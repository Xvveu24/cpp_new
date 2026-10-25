#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cctype>
using namespace std;

int main()
{
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    map<string, int> words;
    string word;
    stringstream textStream(text);

    while (textStream >> word)
    {
        for (char& symbol : word)
        {
            symbol = static_cast<char>(tolower(static_cast<unsigned char>(symbol)));
        }

        size_t first = word.find_first_not_of(".,!?;:\"()[]{}'");
        if (first == string::npos)
        {
            continue;
        }

        size_t last = word.find_last_not_of(".,!?;:\"()[]{}'");
        word = word.substr(first, last - first + 1);

        words[word]++;
    }

    if (words.empty())
    {
        cout << "No words found.\n";
        return 0;
    }

    cout << "Word frequencies:\n";
    for (const auto& entry : words)
    {
        cout << entry.first << " -> " << entry.second << '\n';
    }

    string mostFrequentWord;
    int maximumCount = 0;

    for (const auto& entry : words)
    {
        if (entry.second > maximumCount)
        {
            mostFrequentWord = entry.first;
            maximumCount = entry.second;
        }
    }

    cout << "Most frequent: " << mostFrequentWord
         << " -> " << maximumCount << '\n';
}
