#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(const string& expression)
{
    stack<char> brackets;

    for (char symbol : expression)
    {
        if (symbol == '(' || symbol == '[' || symbol == '{')
        {
            brackets.push(symbol);
        }
        else if (symbol == ')' || symbol == ']' || symbol == '}')
        {
            if (brackets.empty())
            {
                return false;
            }

            char openingBracket = brackets.top();
            brackets.pop();

            if ((symbol == ')' && openingBracket != '(') ||
                (symbol == ']' && openingBracket != '[') ||
                (symbol == '}' && openingBracket != '{'))
            {
                return false;
            }
        }
    }

    return brackets.empty();
}

int main()
{
    string expression;

    while (true)
    {
        cout << "Enter expression (exit to stop): ";
        getline(cin, expression);

        if (expression == "exit")
        {
            break;
        }

        if (isValid(expression))
        {
            cout << "Correct\n";
        }
        else
        {
            cout << "Error\n";
        }
    }
}
